# CMGPD-LN 
This folder here provides the necessary C++ codes for generating the occupational information from the DATASET information and the POSITION_CODE 
information provided by the datasets. 
I thank Xinrui Zhu from Department of Computer Science at Tsinghua University for the help. 

# how to use this codes 
1. Compling the C++ codes in Visual Studio and generate the .exe files. 
2. Input the inqury occupation (in Hanyu Pinyin) and the program would give out the referring number of DATASET and POSITION_CODE (or POSITION_CODE_2)
  in the following form:
  "replace %occupation% =1 if DATASET==%''% & “POSITION_CODE==%''%"
3. Paste the output sentences into the Stata file of CMGPD-LN, and it would automatically generate the occupational variables. 
