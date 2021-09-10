CXXFLAGS:=-Wall

assignment=hw6

$(assignment).a: Serial.o
	ar rcs $@ $^

Serial.o:: Serial.h
testprog.o:: Serial.h

test: testprog
	./testprog

testprog: testprog.o $(assignment).a
	$(CXX) $(CXXFLAGS) -o $@ $^

tar:
	tar -cv $(MAKEFILE_LIST) Serial.cc Serial.h >$(assignment).tar

clean:
	rm -f a.out testprog *.a *.tar *.o