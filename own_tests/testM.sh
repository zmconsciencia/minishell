#!/nfs/homes/bde-seic/Desktop/minishell/minishell

echo hello world
echo $?
echo "hello world"
echo $?
echo 'hello world'
echo $?
echo hello'world'
echo $?
echo hello""world
echo $?
echo ''
echo $?
echo "$PWD"
echo $?
echo '$PWD'
echo $?
echo "aspas ->'"
echo $?
echo "aspas -> ' "
echo $?
echo 'aspas ->"'
echo $?
echo 'aspas -> " '
echo $?
echo "> >> < * ? [ ] | ; [ ] || && ( ) & # $ \ <<"
echo $?
echo '> >> < * ? [ ] | ; [ ] || && ( ) & # $ \ <<'
echo $?
echo "exit_code ->$? user ->$USER home -> $HOME"
echo $?
echo 'exit_code ->$? user ->$USER home -> $HOME'
echo $?
echo "$"
echo $?
echo '$'
echo $?
echo $
echo $?
echo $?
echo $?
echo $?HELLO
echo $?
pwd
echo $?
pwd oi
echo $?
export hello
echo $?
export HELLO=123
echo $?
export A-
echo $?
export HELLO=123 A
echo $?
export HELLO="123 A-"
echo $?
export hello world
echo $?
export HELLO-=123
echo $?
export =
echo $?
export 123
echo $?
unset
echo $?
unset HELLO
echo $?
unset HELLO1 HELLO2
echo $?
unset HOME
echo $?
unset PATH
echo $?
unset SHELL
echo $?
cd $PWD
echo $?
cd $PWD hi 
echo $?
cd 123123
echo $?
exit 123
echo $?
exit 298
echo $?
exit +100
echo $?
exit "+100"
echo $?
exit +"100"
echo $?
exit -100
echo $?
exit "-100"
echo $?
exit -"100"
echo $?
exit hello
echo $?
exit 42 world
echo $?
exit 9223372036854775807
echo $?
exit 9223372036854775808
echo $?
exit -9223372036854775807
echo $?
exit -9223372036854775808
echo $?
exit -9223372036854775809
echo $?
echo "_____________pipes"
env | sort | grep -v SHLVL | grep -v ^_
echo $?
export | sort | grep -v SHLVL | grep -v "declare -x _" | grep -v "PS.="
echo $?
cat ./test_files/infile_big | grep oi
echo $?
cat minishell.h | grep ");"$
echo $?
export GHOST=123 | env | grep GHOST
echo $?
echo "___redirects"
grep hi <./test_files/infile
echo $?
grep hi "<infile" <         ./test_files/infile
echo $?
echo hi < ./test_files/infile bye bye
echo $?
grep hi <./test_files/infile_big <./test_files/infile
echo $?
echo <"./test_files/infile" "bonjour       42"
echo $?
cat <"./test_files/file name with spaces"
echo $?
cat <./test_files/infile_big ./test_files/infile
echo $?
cat <"1""2""3""4""5"
echo $?
echo <"./test_files/infile" <missing <"./test_files/infile"
echo $?
echo <missing <"./test_files/infile" <missing
echo $?
cat <"./test_files/infile"
echo $?
echo <"./test_files/infile_big" | cat <"./test_files/infile"
echo $?
echo $?
echo <"./test_files/infile_big" | cat "./test_files/infile"
echo $?
echo <"./test_files/infile_big" | echo <"./test_files/infile"
echo $?
echo hi | cat <"./test_files/infile"
echo $?
echo hi | cat "./test_files/infile"
echo $?
cat <"./test_files/infile" | echo hi
echo $?
cat <"./test_files/infile" | grep hello
echo $?
cat <"./test_files/infile_big" | echo hi
echo $?
cat <missing
echo $?
cat <missing | cat
echo $?
cat <missing | echo oi
echo $?
cat <missing | cat <"./test_files/infile"
echo $?
echo <123 <456 hi | echo 42
echo $?
ls >./outfiles/outfile01
echo $?
ls >         ./outfiles/outfile01
echo $?
echo hi >         ./outfiles/outfile01 bye
echo $?
ls >./outfiles/outfile01 >./outfiles/outfile02
echo $?
ls >./outfiles/outfile01 >./test_files/invalid_permission
echo $?
ls >"./outfiles/outfile with spaces"
echo $?
ls >"./outfiles/outfile""1""2""3""4""5"
echo $?
ls >"./outfiles/outfile01" >./test_files/invalid_permission >"./outfiles/outfile02"
echo $?
ls >./test_files/invalid_permission >"./outfiles/outfile01" >./test_files/invalid_permission
echo $?
cat <"./test_files/infile" >"./outfiles/outfile01"
echo $?
echo hi >./outfiles/outfile01 | echo bye
echo $?
echo hi >./outfiles/outfile01 >./outfiles/outfile02 | echo bye
echo $?
echo hi | echo >./outfiles/outfile01 bye
echo $?
echo hi | echo bye >./outfiles/outfile01 >./outfiles/outfile02
echo $?
echo hi >./outfiles/outfile01 | echo bye >./outfiles/outfile02
echo $?
echo hi >./outfiles/outfile01 >./test_files/invalid_permission | echo bye
echo $?
echo hi >./test_files/invalid_permission | echo bye
echo $?
echo hi >./test_files/invalid_permission >./outfiles/outfile01 | echo bye
echo $?
echo hi | echo bye >./test_files/invalid_permission
echo $?
echo hi | >./outfiles/outfile01 echo bye >./test_files/invalid_permission
echo $?
echo hi | echo bye >./test_files/invalid_permission >./outfiles/outfile01
echo $?
cat <"./test_files/infile" >./test_files/invalid_permission
echo $?
cat >./test_files/invalid_permission <"./test_files/infile"
echo $?
cat <missing >./outfiles/outfile01
echo $?
cat >./outfiles/outfile01 <missing
echo $?
cat <missing >./test_files/invalid_permission
echo $?
cat >./test_files/invalid_permission <missing
echo $?
cat >./outfiles/outfile01 <missing >./test_files/invalid_permission
echo $?
ls >>./outfiles/outfile01
echo $?
ls >>      ./outfiles/outfile01
echo $?
ls >>./outfiles/outfile01 >./outfiles/outfile01
echo $?
ls >./outfiles/outfile01 >>./outfiles/outfile01
echo $?
ls >./outfiles/outfile01 >>./outfiles/outfile01 >./outfiles/outfile02
echo $?
ls >>./outfiles/outfile01 >>./outfiles/outfile02
echo $?
ls >>./test_files/invalid_permission
echo $?
ls >>./test_files/invalid_permission >>./outfiles/outfile01
echo $?
ls >>./outfiles/outfile01 >>./test_files/invalid_permission
echo $?
ls >./outfiles/outfile01 >>./test_files/invalid_permission >>./outfiles/outfile02
echo $?
ls <missing >>./test_files/invalid_permission >>./outfiles/outfile02
echo $?
ls >>./test_files/invalid_permission >>./outfiles/outfile02 <missing
echo $?
echo hi >>./outfiles/outfile01 | echo bye
echo $?
echo hi >>./outfiles/outfile01 >>./outfiles/outfile02 | echo bye
echo $?
echo hi | echo >>./outfiles/outfile01 bye
echo $?
echo hi | echo bye >>./outfiles/outfile01 >>./outfiles/outfile02
echo $?
echo hi >>./outfiles/outfile01 | echo bye >>./outfiles/outfile02
echo $?
echo hi >>./test_files/invalid_permission | echo bye
echo $?
echo hi >>./test_files/invalid_permission >./outfiles/outfile01 | echo bye
echo $?
echo hi | echo bye >>./test_files/invalid_permission
echo $?
echo hi | echo >>./outfiles/outfile01 bye >./test_files/invalid_permission
echo $?
cat <minishell.h>./outfiles/outfile
echo $?
cat <minishell.h|ls
echo $?
echo "___extras"
$PWD
echo $?
$EMPTY
echo $?
$EMPTY echo hi
echo $?
./test_files/invalid_permission
echo $?
./missing.out
echo $?
missing.out
echo $?
"aaa"
echo $?
test_files
echo $?
./test_files
echo $?
/test_files
echo $?
minishell.h
echo $?
$
echo $?
$?
echo $?
README.md
echo $?