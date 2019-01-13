integrators = euler.o runge-kutta.o adams-bashforth.o
equations = duffing.o lorenz.o linear-oscillator.o
objects = ode_solve.o $(integrators) $(equations)
#equation_test= linear-oscillator.o
#object_test = test_convergence.o $(integrators) $(equation_test)

CXXFLAGS = -g -Wall

all: ode_solve

ode_solve : $(objects)
	$(CXX) -o $@ $^ -lm

#test_convergence : $(object_test)
#	$(CXX) -o $@ $^ -lm

clean:
	$(RM) *.o
	$(RM) project.depend

# The code below helps auto-generate dependencies in a separate file,
# which then gets "included" into this Makefile
depend:
	$(CXX) -MM $(CXXFLAGS) *.cc > project.depend

-include project.depend
