cd ..
cd ATMController
./atmlibbuilder.sh
cd ..
cd testmain

mkdir include
cp ../ATMController/include/* ./include/
mkdir lib
cp ../ATMController/lib/libatm_controller.so ./lib/libatm_controller.so

mkdir build
cd build
rm -rf *
cmake ..
make -j4

cd build
./atm_tester