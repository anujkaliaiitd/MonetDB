import re
import os
import sys
import getopt

def parse_cmd(line):
    b = re.search(r'\bwhere \w+\b',line)
    if b == None:
        return
    return b.group(0)[6:]

def parse_time(line):
    b = re.search(r'\btuple ?\(\d+\.\d+\w+',line)
    if b == None:
        return
    return b.group(0)[7:]

def parse_result(file_name, to_file_name):
    f = open(file_name, 'r')
    w = open(to_file_name, 'w')
    cnt = 0
    for line in f:
        cmd = parse_cmd(line)
        time = parse_time(line)
        if cmd != None and cmd == "match":
            cnt +=1
            tmp = "--------------------\n"
            tmp += "time for query " + str(cnt) + "\n" 
            tmp += "--------------------\n"
        if cmd != None:
            tmp += cmd + "  "
        if time != None:
            tmp += time + " \n"
            w.write(tmp)
            tmp = ""

    w.close()
    f.close()

def main(argv):
    file_name = 'result.csv'
    to_file_name = 'parse.txt'
    try:                                
        opts, args = getopt.getopt(argv, "hf:t:", ["help", "from=", "to="])
    except getopt.GetoptError:          
        sys.exit(2)                     
    for opt, arg in opts:                
        if opt in ("-h", "--help"):      
            print "python parse_result.py -f [fromfile] -t [tofile]"                
            sys.exit()                  
        elif opt in ("-f", "--from"): 
            file_name = arg     
        elif opt in ("-t", "--to"):
            to_file_name = arg

    parse_result(file_name, to_file_name)
    print "parse result from file %s to file %s" % (file_name, to_file_name)

if __name__ == "__main__":
    main(sys.argv[1:])

