#!/bin/bash
g++ main.cpp mergesort.hpp mergesort.cpp
echo "Build completed."
../../Sonar/build-wrapper-linux-x86/build-wrapper-linux-x86-64 --out-dir bw-output g++ main.cpp mergesort.cpp mergesort.hpp
../../Sonar/sonar-scanner-4.3.0.2102-linux/sonar-scanner -D"sonar.organization=gabridc" -D"sonar.projectKey=gabridc_CPP-Guidelines-and-Examples" -D"sonar.sources=." -D"sonar.host.url=https://sonarcloud.io" -D"sonar.cfamily.build-wrapper-output=bw-output" -D"sonar.login=24ad0b359e7624e877205567399328b92835dcbc"
pause