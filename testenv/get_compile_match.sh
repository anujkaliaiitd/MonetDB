#grep "cre2compile" tmp | grep -o '[0-9]\+.[0-9]\+' | awk '{sum+=$0} END {print "cre2compile AVG=",sum/NR}'
#grep "cre2match" tmp | grep -o '[0-9]\+.[0-9]\+' | awk '{sum+=$0} END {print "cre2matchAVG=",sum/NR}'
#
#grep "pcrecompile" tmp | grep -o '[0-9]\+.[0-9]\+' | awk '{sum+=$0} END {print "pcrecompile AVG=",sum/NR}'
#grep "pcrematch" tmp | grep -o '[0-9]\+.[0-9]\+' | awk '{sum+=$0} END {print "pcrematch AVG=",sum/NR}'
#
#grep "dfapcrematch" tmp | grep -o '[0-9]\+.[0-9]\+' | awk '{sum+=$0} END {print "dfapcrecompile AVG=",sum/NR}'
#
#grep "hyperscancompile" tmp | grep -o '[0-9]\+.[0-9]\+' | awk '{sum+=$0} END {print "hyperscancompile AVG=",sum/NR}'
#grep "hyperscanmatch" tmp | grep -o '[0-9]\+.[0-9]\+' | awk '{sum+=$0} END {print "hyperscanmatch AVG=",sum/NR}'
#
#grep "lvz compile" tmp | grep -o '[0-9]\+.[0-9]\+' | awk '{sum+=$0} END {print "hyperscancompile AVG=",sum/NR}'
#grep "lvzmatch" tmp | grep -o '[0-9]\+.[0-9]\+' | awk '{sum+=$0} END {print "hyperscanmatch AVG=",sum/NR}'
#echo "*****************"


grep "lvz compile" tmp | grep -o '[0-9]\+.[0-9]\+' | awk '{sum+=$0} END {print "hyperscancompile AVG=",sum/NR}'
grep "lvzmatch" tmp | grep -o '[0-9]\+.[0-9]\+' | awk '{sum+=$0} END {print "hyperscanmatch AVG=",sum/NR}'
echo "*****************"
