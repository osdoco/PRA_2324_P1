bin/testListArray: testListArray.cpp ListArray.h List.h
        mkdir -p bin
        g++ -o bin/testListArray testListArray.cpp ListArray.h
