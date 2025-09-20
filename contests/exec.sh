echo "--- $1.cpp をビルドします ---"
g++ "$1.cpp" -o "$1".out
clear

echo "--- $1 を実行します ---"
"./$1".out