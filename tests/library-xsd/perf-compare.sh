#!/bin/sh

#query="//name"
query="/lib:catalog/book/author/name"

for i in {1..7}
do
#./libxml2-perf library-large$i.xml $query lib=http://www.codesynthesis.com/library
  ./driver library-large$i.xml
  ./lxml-perf.py library-large$i.xml
  echo -e "library-large$i.xml\n"
done
exit

