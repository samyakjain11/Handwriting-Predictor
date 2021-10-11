# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.17.3)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(catch2-populate NONE)

include(ExternalProject)
ExternalProject_Add(catch2-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_REPOSITORY" "https://github.com/catchorg/Catch2.git"
                    SOURCE_DIR          "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/cinder_0.9.2_mac/my-projects/naivebayes-samyakjain11-f4f4ece543e3bc78596b894ead37c7f91e567fc4/cmake-build-debug/_deps/catch2-src"
                    BINARY_DIR          "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/cinder_0.9.2_mac/my-projects/naivebayes-samyakjain11-f4f4ece543e3bc78596b894ead37c7f91e567fc4/cmake-build-debug/_deps/catch2-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)
