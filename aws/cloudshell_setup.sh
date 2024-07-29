echo "Setting up cloudshell environment"

yes | sudo yum install gcc-c++
yes | sudo yum install libcurl-devel
yes | sudo yum install cmake
yes | sudo yum install ninja-build

# Install vcpkg
pushd .
sudo mkdir /home/vcpkg
sudo chown cloudshell-user /home/vcpkg
cd /home/vcpkg
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg && ./bootstrap-vcpkg.sh
export VCPKG_ROOT=/home/vcpkg/vcpkg
export PATH=$VCPKG_ROOT:$PATH
popd

cmake --preset=default

