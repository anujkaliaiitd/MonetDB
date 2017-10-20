import re
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

def parse_result(file_name):
    f = open(file_name, 'r')
    w = open('parse.txt', 'w')
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

parse_result('result.csv')


