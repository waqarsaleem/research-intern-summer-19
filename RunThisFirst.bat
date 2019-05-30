g++ PPMOutput.cpp -o PPMOutput.exe -std=c++11
PPMOutput.exe > output.ppm
pnmtopng.exe output.ppm > out.png