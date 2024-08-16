echo "Compiling plugin..."

buildf="build"
if [ ! -d "$buildf" ]; then
    mkdir "$buildf"
fi

cd $buildf
cmake -G Ninja ..
ninja
cd ../

cp bin/libmyplugin.so server/plugins/