About DES Code Source
=====================
 Author : huangjinqiang  
  Email : hellojinqiang@gmail.com   
   Date : 2014-11-5  
Compiler: gcc version 4.9.1  

Usage:
	
	ssh public@117.78.8.149
	# password: 123456

Expiration date:

	2014-11-27

If you are logged in this machine, you need to do:

	public(^_^)@JiangCentOS(~)$ cd des
	public(^_^)@JiangCentOS(des)$ ls
	about_des.md  des.cpp  des.h  des_test.cpp  main  makefile
	public(^_^)@JiangCentOS(des)$ make
	g++ -c des.cpp
	g++ -c des_test.cpp
	g++ -o main des.o des_test.o
	public(^_^)@JiangCentOS(des)$ ./main 
	Enter a string(<=128): Johnny is Huang Jinqiang's English Name.
	Before encrypting: [Johnny is Huang Jinqiang's English Name.]
	After  encrypting: [F��.E�?�:�s$^f����.�v�}?�o�o�^T#ɻM��T]
	After  decrypting: [Johnny is Huang Jinqiang's English Name.]
	public(^_^)@JiangCentOS(des)$ ls
	about_des.md  des.h  des_test.cpp  main
	des.cpp       des.o  des_test.o    makefile
	public(^_^)@JiangCentOS(des)$ make clean
	rm *.o
	public(^_^)@JiangCentOS(des)$ ls
	about_des.md  des.cpp  des.h  des_test.cpp  main  makefile
	public(^_^)@JiangCentOS(des)$ 
	

