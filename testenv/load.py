import pymonetdb
table_name = "regextest"

def load(file_path):
	connection = pymonetdb.connect(username="monetdb", password="monetdb", hostname="localhost", database="demo")
	cursor = connection.cursor()
	try:
		cursor.execute("drop table %s" % table_name)
	except:
		print "table not exist can not drop"
	try:
		cursor.execute("create table if not exists %s (name VARCHAR(256));" % table_name)
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
			if count % 1000 == 0:
				connection.commit()
		except:
			print cmd
	connection.commit()
	cmd = "select count(*) from %s" % table_name
	cursor.execute(cmd)
	print cursor.fetchone()
	
file_path =  "/home/xzhang3/testenv/string-generator/generate.out"
load(file_path)


