#!/bin/bash
for FILENAME in "$@"
do
if [ -e "$FILENAME" ]
then
if [ -d "$HOME/TRASH" ]
then 
mv $PWD/$FILENAME /$HOME/TRASH/
echo "Given FILENAME $FILENAME is moved to TRASH!"
else
echo "Trash Directory doesn not exist. Created one now!"
mkdir /$HOME/TRASH
mv $PWD/$FILENAME /$HOME/TRASH/
echo "Given FILENAME $FILENAME is moved to TRASH!"
fi
else
echo "Please check the FILENAME $FILENAME.Given FILENAME $FILENAME does not exist"
fi
done
find $HOME/TRASH -cmin +60 -type f -delete
echo "All the files in TRASH that are there for more than 60 minutes are deleted!"
