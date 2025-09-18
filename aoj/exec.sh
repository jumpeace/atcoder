if [ ! -f "$1" ]; then
    echo "--- $1.cpp をビルドします ---"
    g++ "$1.cpp" -o "$1"
    clear
fi
echo "--- $1 を実行します ---"
"./$1"