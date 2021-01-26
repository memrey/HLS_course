
int main(){

	int status = 0;
	unsigned char a,b;
	for(int i=0; i<256; i++){
		a=(unsigned char)i;
		basic_input_output(a,&b);
		if(b!=a){
			status = -1;
			break;
		}
	}
	if(status == 0){
		std::cout<<"test passed"<<std::endl;
	}
	else{
		std::cout<<"test failed"<<std::endl;
	}

	return status;
}
