1)to compile you just need to type make in the terminal,if it doesn't compile you need to change the OTHER_INCLUDE1 (or OTHER_INCLUDE2) pax-examples/Examples/lib folder in the makefile file,or you need you to change LIB_PATH to your own pax-examples/Examples/lib folder(here i have already provided paths LIB_PATH1 LIB_PATH2)

2)you can change the parameters of the solver in the .pot file,you can also change the function here bacause i used mu_parser to read the function from a file.If you want to plot the error you need to provide the exact solution in the file and set save_error to true.

2)to launch the program just type ./main in the terminal there you can choose the type of solver you want,then when you are finish just type quit.

3)after you have typed quit you can plot the errors(if you have provided an exact sol) by the typingplot_error_nameofthesolver.sh
for instance: -> plot_error_Bisection.sh -> plot_error_QuasiNewton.sh    ->plot_error_Secant.sh 

