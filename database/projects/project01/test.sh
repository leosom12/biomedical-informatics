VAR=$(ls q*)

for i in $(echo $VAR);
do
    echo "$i\n"
    cat $i | sqlite3 tpch.db
    echo "\n"
done
