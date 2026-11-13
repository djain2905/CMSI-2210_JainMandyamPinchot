del testresults.txt
gcc dec2bin.c -o dec2bin                           >> testresults.txt
gcc dec2hex.c -o dec2hex                           >> testresults.txt
gcc timesTables.c -o timesTables                   >> testresults.txt
gcc holdit.c -o holdit                             >> testresults.txt
gcc wordcount.c -o wordcount                       >> testresults.txt
echo .                                             >> testresults.txt
echo ============================                  >> testresults.txt
echo running tests on dec2bin                      >> testresults.txt
echo ============================                  >> testresults.txt
echo test dec2bin no arguments                     >> testresults.txt
echo expecting error message                       >> testresults.txt
dec2bin                                            >> testresults.txt
echo test dec2bin 5                                >> testresults.txt
echo expecting 00000000000000000000000000000101    >> testresults.txt
dec2bin 5                                          >> testresults.txt
echo test dec2bin 123456                           >> testresults.txt
echo expecting 00000000000000011110001001000000    >> testresults.txt
dec2bin 123456                                     >> testresults.txt
echo test dec2bin 65535                            >> testresults.txt
echo expecting 00000000000000001111111111111111    >> testresults.txt
dec2bin 65535                                      >> testresults.txt
echo test dec2bin 977272832                        >> testresults.txt
echo expecting 00111010010000000000000000000000    >> testresults.txt
dec2bin 977272832                                  >> testresults.txt
echo test dec2bin 1073746484                       >> testresults.txt
echo expecting 01000000000000000001001000110100    >> testresults.txt
dec2bin 1073746484                                 >> testresults.txt
echo .                                             >> testresults.txt
echo ============================                  >> testresults.txt
echo running tests on dec2hex                      >> testresults.txt
echo ============================                  >> testresults.txt
echo test dec2hex no arguments                     >> testresults.txt
echo expecting error message                       >> testresults.txt
dec2hex                                            >> testresults.txt
echo test dec2hex bogus argument                   >> testresults.txt
echo expecting error message                       >> testresults.txt
dec2hex 65535 15                                   >> testresults.txt
echo test dec2hex 5                                >> testresults.txt
echo expecting 0x00000005                          >> testresults.txt
dec2hex 5                                          >> testresults.txt
echo test dec2hex 123456 8                         >> testresults.txt
echo expecting 0x0001E240                          >> testresults.txt
dec2hex 123456 8                                   >> testresults.txt
echo test dec2hex 65535                            >> testresults.txt
echo expecting 0x000FFFF                           >> testresults.txt
dec2hex 65535                                      >> testresults.txt
echo test dec2hex 977272832 8                      >> testresults.txt
echo expecting 0x3A400000                          >> testresults.txt
dec2hex 977272832 8                                >> testresults.txt
echo test dec2hex 1073746484 8                     >> testresults.txt
echo expecting 0x40001234                          >> testresults.txt
dec2hex 1073746484 8                               >> testresults.txt
echo test dec2hex 5 16                             >> testresults.txt
echo expecting 0x0000000000000005                  >> testresults.txt
dec2hex 5 16                                       >> testresults.txt
echo test dec2hex 123456 16                        >> testresults.txt
echo expecting 0x000000000001E240                  >> testresults.txt
dec2hex 123456 16                                  >> testresults.txt
echo test dec2hex 977272832 16                     >> testresults.txt
echo expecting 0x000000003A400000                  >> testresults.txt
dec2hex 977272832 16                               >> testresults.txt
echo test dec2hex 1073746484 default               >> testresults.txt
echo expecting 0x40001234                          >> testresults.txt
dec2hex 1073746484                                 >> testresults.txt
echo .                                             >> testresults.txt
echo ============================                  >> testresults.txt
echo running tests on timesTables                  >> testresults.txt
echo ============================                  >> testresults.txt
echo test timesTables default                      >> testresults.txt
timesTables                                        >> testresults.txt
echo .                                             >> testresults.txt
echo test timesTables 2                            >> testresults.txt
timesTables 2                                      >> testresults.txt
echo .                                             >> testresults.txt
echo test timesTables 5                            >> testresults.txt
timesTables 5                                      >> testresults.txt
echo .                                             >> testresults.txt
echo test timesTables 10                           >> testresults.txt
timesTables 10                                     >> testresults.txt
echo .                                             >> testresults.txt
echo test timesTables 12                           >> testresults.txt
timesTables 12                                     >> testresults.txt
echo .                                             >> testresults.txt
echo test timesTables 13                           >> testresults.txt
timesTables 13                                     >> testresults.txt
echo .                                             >> testresults.txt
echo test timesTables 32                           >> testresults.txt
timesTables 32                                     >> testresults.txt
echo .                                             >> testresults.txt
echo ============================                  >> testresults.txt
echo running test on holdit                        >> testresults.txt
echo ============================                  >> testresults.txt
holdit                                             >> testresults.txt
echo .                                             >> testresults.txt
echo ============================                  >> testresults.txt
echo running test on wordcount                     >> testresults.txt
echo ============================                  >> testresults.txt
echo test wordcount no arguments                   >> testresults.txt
wordcount                                          >> testresults.txt
echo expecting message or error                    >> testresults.txt
echo test wordcount on non-existant blah.txt       >> testresults.txt
echo expecting message or error                    >> testresults.txt
wordcount blah.txt                                 >> testresults.txt
echo test wordcount on inputfile.txt               >> testresults.txt
echo expecting 397 words plus or minus one         >> testresults.txt
wordcount inputfile.txt                            >> testresults.txt
