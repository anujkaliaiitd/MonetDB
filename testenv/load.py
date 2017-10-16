import pymonetdb
import os
table_name = "regextest"

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

file_path =  os.path.join(os.path.dirname(os.path.abspath(__file__)), "string-generator/generate.out")
load(file_path)


