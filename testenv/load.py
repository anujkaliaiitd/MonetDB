import pymonetdb
import os
import sys
import getopt
table_name = "regextest"
file_name = 'generate.out'

def load(file_path):
	connection = pymonetdb.connect(username="monetdb", password="monetdb", hostname="localhost", database="demo")
	cursor = connection.cursor()
	try:    
                cmd = "drop table if exists %s;" % table_name
		cursor.execute(cmd)
                connection.commit()
	except:
		print "table not exist can not drop"
	try:
                cmd = "create table if not exists %s (name VARCHAR(1000));" % table_name
		cursor.execute(cmd)
		connection.commit()
	except:
		print "table exists"
	f = open(file_path)
	count = 0
	for line in f:
		pos = line.find('|')
		line = line[pos+1:]
		line = line.strip()
		line = line.replace("'", "")
		count += 1
		try:
			cmd = """INSERT INTO %s VALUES ('%s');""" % (table_name, line)
			cursor.execute(cmd)
			if count % 10000 == 0:
				connection.commit()
                        if count % 10000 == 0:
                                print count
		except:
                        return
			#print cmd
	connection.commit()
	cmd = "select count(*) from %s" % table_name
	cursor.execute(cmd)
	print cursor.fetchone()

def main(argv):
    file_name = 'generate.out'
    try:                                
        opts, args = getopt.getopt(argv, "hf:", ["help", "file="])
    except getopt.GetoptError:          
        sys.exit(2)                     
    for opt, arg in opts:                
        if opt in ("-h", "--help"):      
            print "python load.py -f [yourfile]"                    
            sys.exit()                  
        elif opt in ("-f", "--file"): 
            file_name = arg               
    path = "string-generator/" + file_name
    file_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), path)
    print "load file %s to regex" % file_path
    load(file_path)

if __name__ == "__main__":
    main(sys.argv[1:])



