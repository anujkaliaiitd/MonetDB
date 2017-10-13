/**
 * @author David Sidler <david.sidler@inf.ethz.ch>
 * (c) 2017, ETH Zurich, Systems Group
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <utility>
#include <random>

#include <boost/program_options.hpp>
namespace po = boost::program_options;

int create_db_input(std::ifstream& inputFile, std::vector<std::string>& strings, int stringLen, int stringNum)
{
   std::string prevLine = "";
   std::string line;
   int len;
   int j = 0;
   int currLen = 0;
   std::stringstream ss;
   while (j < stringNum)
   {
      if (prevLine.length() > stringLen)
      {
         ss << prevLine.substr(0, stringLen);
         prevLine = prevLine.substr(stringLen);
         currLen += stringLen;
         //std::cout << "j: " << j << " b3" << std::endl;
      }
      else
      {
         ss << prevLine;
         currLen += prevLine.length();
         prevLine = "";
         //std::cout << "j: " << j << " b4" << std::endl;
      }
      while (currLen < stringLen)
      {
         getline(inputFile, line);
         //Rewind in case of EOF
         if (inputFile.eof())
         {
            inputFile.clear();
            inputFile.seekg(0, std::ios::beg);
         }
         if (line.length() > stringLen-currLen)
         {
            ss << line.substr(0, stringLen-currLen);
            prevLine = line.substr(stringLen-currLen);
            currLen += (stringLen-currLen);
            //std::cout << "j: " << j << " b1" << std::endl;
         }
         else
         {
            ss << line;
            currLen += line.length();
            //std::cout << "j: " << j << " b2" << std::endl;
         }
      }
      strings.push_back(ss.str());
      j++;
      currLen = 0;
      ss.str(std::string());
      ss.clear();
   }
   std::cout << "created: " << j << " strings" << std::endl;
}

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine rand_gen(seed);
std::uniform_int_distribution<int> distr15(1,5);
std::uniform_int_distribution<int> distr110(1,10);
std::uniform_int_distribution<int> charDistr(0,25);

std::string getInsertForPattern(int patternType)
{
   std::ostringstream oss;
   bool coin = (distr110(rand_gen) < 6);
   int rand;
   char rc;

   switch(patternType)
   {
      case 0:
         oss << "Strasse";
         break;
      case 1:
         oss << "Alan";
         for (int i = distr15(rand_gen); i > 0; i--) {
            oss << " ";
         }
         oss << "Turing";
         for (int i = distr15(rand_gen)+5; i > 0; i--) {
            oss << " ";
         }
         oss << "Cheshire";
         break;
      case 2:
         if (!coin) {
            oss << "Strasse";
         }
         else {
            oss << "Str.";
         }
         for (int i = distr110(rand_gen); i > 0; i--) {
            oss << " ";
         }
         oss << "8";
         oss << distr110(rand_gen)-1;
         oss << distr110(rand_gen)-1;
         oss << distr110(rand_gen)-1;
         oss << distr110(rand_gen)-1;
         break;
      case 3: //[0-9]+(USD|EUR|GBP)
         oss << distr110(rand_gen)-1;
         rand = distr110(rand_gen)-1;
         if (rand < 3)
         {
            oss << "USD";
         }
         else if (rand < 6)
         {
            oss << "EUR";
         }
         else
         {
            oss << "GBP";
         }
         break;
      case 4: //[a-Za-z]{3+}:[0-9]{4}
         for (int i = distr15(rand_gen)+4; i > 0; i--)
         {
            //Add random character
            if (coin)
            {
               rc = 'a' + charDistr(rand_gen);
            }
            else
            {
               rc = 'A' + charDistr(rand_gen);
            }
            oss << rc;
         }
         oss << ":";
         for (int i = 0; i < 4; i++)
         {
            oss << distr110(rand_gen)-1;
         }
         break;
      case 5:
         oss << "";
         break;
   }
   return oss.str();
}


void insert_hits_simple(std::vector<std::string>& strings,
                  int patternType, int posChoice, double selectivity)
{
   int count = 0;
   int startPos = posChoice-1;
   if (posChoice == 0) {
      startPos = 0;
   }
   //std::default_random_engine generator(seed);
   std::uniform_real_distribution<double> distribution(0.0,1.0);

   std::vector<std::string>::iterator it;
   for (it = strings.begin(); it != strings.end(); ++it)
   {
      double prop = distribution(rand_gen);
      //cout << "prop: " << prop << endl;
      if (prop <= selectivity)
      {
         std::string insert = getInsertForPattern(patternType);
         size_t len = it->length();
         int pos = (len/4)*startPos;
         if (len-pos < insert.length()) {
            pos = len - insert.length();
         }
         it->replace(pos, insert.length(), insert);

         if (posChoice == 0) {
            (startPos == 3) ? startPos = 0 : startPos++;
         }
         count++;
      } //prop
   }
   std::cout << "Inserted " << count << " hits." << std::endl;
}


int main(int argc, char **argv){

   const char* regex_pattern[3] = {"Strasse", "Alan.*Turing.*Cheshire", "(Strasse|Str.).*(8\\d{4})"};
   po::options_description desc("Allowed options");

   desc.add_options()
      ("help", "produce help message")
      ("input-file", po::value<std::string>(), "input file")
      ("string-len", po::value<int>(), "length of strings")
      ("num-string", po::value<int>(), "number of strings")
      ("pattern", po::value<int>(), "[1]: substring, [2]: multi-substring, [3] complex1")
      ("pattern-pos", po::value<int>(), "[0]: random, [1-4] quarter")
      ("selectivity", po::value<double>(), "probability of hit in row x, [0.0-1.0]")
   ;

   po::positional_options_description pd;
   pd.add("input-file", 1);

   po::variables_map vm;
   po::store(po::parse_command_line(argc, argv, desc), vm);
   po::notify(vm);    

   if (vm.count("help")) {
      std::cout << desc << "\n";
      return 1;
   }

   std::string filename;
   int numString = 10;
   int stringLen = 64;
   //layoutType pageType = SIMPLE;
   int patternType = 0;
   int patternPos = 0;
   double selectivity = 0.0;
   
   if (vm.count("input-file")) {
      std::cout << "Using input: " << vm["input-file"].as<std::string>() << std::endl;
      filename = vm["input-file"].as<std::string>();
   } else {
      std::cout << "No input filed defined.\n";
      return 1;
   }
   
   if (vm.count("num-string")) {
      numString = vm["num-string"].as<int>();
   }


   if (vm.count("pattern")) {
      patternType = vm["pattern"].as<int>() - 1;
      if (patternType < 0 || patternType > 4) {
         std::cout << "Invalid pattern type, has to be between 1 and 5" << std::endl;
         return 1;
      }
   }

   if (vm.count("string-len")) {
      stringLen = vm["string-len"].as<int>();
      if (stringLen < 1) {
         std::cout << "string length too small, has to be at least 1" << std::endl;
         return 1;
      }
   }
   if (vm.count("pattern-pos")) {
      patternPos = vm["pattern-pos"].as<int>();
      if (patternPos < 0 || patternPos > 4) {
         std::cout << "Invalid pattern position, has to be between 0 and 4" << std::endl;
         return 1;
      }
   }

   if (vm.count("selectivity")) {
      selectivity = vm["selectivity"].as<double>();
      if (selectivity < 0.0 || selectivity > 1.0) {
         std::cout << "invalid selectivity, has to be between 0.0 and 1.0" << std::endl;
         return 1;
      }
   }
  
   std::ifstream inputFile (filename);
   std::vector<std::string> lines;
   if (inputFile.is_open())
   {
      create_db_input(inputFile, lines, stringLen, numString);
      insert_hits_simple(lines, patternType, patternPos, selectivity);
   }
   else {
      std::cout << "Unable to open input file." << std::endl;
      return 1;
   }

   //output lines
   std::ofstream outputFile ("generate.out");
   std::vector<std::string>::const_iterator it;
   int oid = 0;
   //Random generators for price and quantity
   std::default_random_engine generator;
   std::uniform_int_distribution<int> randdist(1, 100000);
   std::poisson_distribution<int>     poisdist(1);
   for (it = lines.begin(); it != lines.end(); ++it)
   {
      // Old verions
      outputFile << oid << "|" << *it << std::endl;
      // Added for Muhsen, price, quantity , revenue
      /*int price = randdist(generator);
      int quantity = poisdist(generator);
      int revenue = price * quantity;
      outputFile << oid << "|" << price << "|" << quantity << "|" << revenue << "|" << *it << std::endl;*/
      oid++;
   }
   outputFile.close();
  
	return 0;
}
