#include <mutex>

#include "../includes/baker.h"
#include "/home/joseph/workspace/410_proj4_SKELETON-master.zip_expanded/410_proj4_SKELETON-master/includes/externs.h"

using namespace std;

Baker::Baker(int id):id(id)
{
}

Baker::~Baker()
{
}

void Baker::bake_and_box(ORDER &anOrder) {
	Box newDonutBox;

	int numberOfDonuts = anOrder.number_donuts;
	while(numberOfDonuts > 0){
		if (numberOfDonuts > 12){
			numberOfDonuts = numberOfDonuts - 12;
			Box tempBox;
			for(int i = 0; i < 12; i++){
				DONUT newDonut;
				tempBox.addDonut(newDonut);
			}

			anOrder.boxes.push_back(tempBox);

		}
		else{
			Box tempBox;
			for(int i = 0; i < numberOfDonuts; i++){
				DONUT newDonut;
				tempBox.addDonut(newDonut);
			}
			anOrder.boxes.push_back(tempBox);
		}
	}
}

void Baker::beBaker() {
	while (!order_in_Q.empty()){
		ORDER thisOrder = order_in_Q.front();
		order_in_Q.pop();
		bake_and_box(thisOrder);
		order_out_Vector.push_back(thisOrder);
		if (b_WaiterIsFinished){
			break;
		}
	}

	
}
