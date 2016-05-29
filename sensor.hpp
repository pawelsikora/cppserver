
using namespace std;

class Sensor
{
	public:
		void add(const char *name, int type){

		}

		void remove(const char *name, int type){

		}

		void writeData(int id, char *message){

		}
		
		int getId(const char *name){
			return 0;
		}

		void printData(int id){

		}
		
		char * readData(int id){
			return NULL;
		}

	private:

		struct{ 
			char name[64];
			int type;
			int id;

		} sensorData_t;


};
