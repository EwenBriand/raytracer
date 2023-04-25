mkdir -p ./build/ && cd ./build/
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build .
mv raytracer ../
mv *.so ../plugins/
cd ..