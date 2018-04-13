#include <string>
#include "stdlib.h"

//#include "../includes/waiter.h"
#include "/home/joseph/workspace/410_proj4_SKELETON-master.zip_expanded/410_proj4_SKELETON-master/includes/waiter.h"

#include "/home/joseph/workspace/410_proj4_SKELETON-master.zip_expanded/410_proj4_SKELETON-master/includes/externs.h"

using namespace std;

Waiter::Waiter(int id,std::string filename):id(id),myIO(filename){

}

Waiter::~Waiter()
{
}

//gets next Order(s) from file_IO
int Waiter::getNext(ORDER &anOrder){

	if (myIO.getNext(anOrder) == SUCCESS){
		return SUCCESS;
	}
	else{
		throw COULD_NOT_OPEN_FILE;
	}




	return SUCCESS;
}

void Waiter::beWaiter() {
	ORDER temp;
	while(getNext(temp)== SUCCESS){
		order_in_Q.push(temp);
		cv_order_inQ.notify_all();
	}
	b_WaiterIsFinished = true;


}

