void myprint(char* msg, int len);

// int choose(int a, int b)
// {
// 	if(a >= b){
// 		myprint("the 1st one\n", 13);
// 	}
// 	else{
// 		myprint("the 2nd one\n", 13);
// 	}

// 	return 0;
// }

// print a string without a len hint
void print(const char *str);

void _main(int arg)
{
	char *msg = "hello world!\n";
	print(msg);
}
