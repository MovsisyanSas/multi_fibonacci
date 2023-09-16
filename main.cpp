#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex mtx;
std::vector<int> fibos;

void random(std::vector<unsigned int>& R) {
	srand(time(0));
	for (int i = 0; i < R.size(); i++)
	{
		R[i] = rand() % 15;
	}
}


int fibo(unsigned int a) {
	mtx.lock();

	if (a <= 2) {
		if (fibos.size() < a) {
			fibos.resize(a, 1);
		}
		mtx.unlock();
		return 1;
	}

	if (fibos.size() >= a) {
		int result = fibos[a - 1];
		mtx.unlock();
		return result;
	}

	mtx.unlock();

	int res = fibo(a - 1) + fibo(a - 2);

	mtx.lock();

	if (fibos.size() < a) {
		fibos.resize(a);
	}

	fibos[a - 1] = res;
	mtx.unlock();

	return res;
}


int main() {
	std::vector<unsigned int> r(20);
	random(r);

	std::thread t1([&]() {
		int res = fibo(r[0]);
		mtx.lock();
		std::cout << "t1:(" << r[0] << ")	 " << res << std::endl;
		mtx.unlock();
		});
	std::thread t2([&]() {
		int res = fibo(r[1]);
		mtx.lock();
		std::cout << "t2:(" << r[1] << ")	 " << res << std::endl;
		mtx.unlock();
		});
	std::thread t3([&]() {
		int res = fibo(r[2]);
		mtx.lock();
		std::cout << "t3:(" << r[2] << ")	 " << res << std::endl;
		mtx.unlock();
		});
	std::thread t4([&]() {
		int res = fibo(r[3]);
		mtx.lock();
		std::cout << "t4:(" << r[3] << ")	 " << res << std::endl;
		mtx.unlock();
		});
	std::thread t5([&]() {
		int res = fibo(r[4]);
		mtx.lock();
		std::cout << "t5:(" << r[4] << ")	 " << res << std::endl;
		mtx.unlock();
		});
	std::thread t6([&]() {
		int res = fibo(r[5]);
		mtx.lock();
		std::cout << "t6:(" << r[5] << ")	 " << res << std::endl;
		mtx.unlock();
		});
	std::thread t7([&]() {
		int res = fibo(r[6]);
		mtx.lock();
		std::cout << "t7:(" << r[6] << ")	 " << res << std::endl;
		mtx.unlock();
		});
	std::thread t8([&]() {
		int res = fibo(r[7]);
		mtx.lock();
		std::cout << "t8:(" << r[7] << ")	 " << res << std::endl;
		mtx.unlock();
		});
	std::thread t9([&]() {
		int res = fibo(r[8]);
		mtx.lock();
		std::cout << "t9:(" << r[8] << ")	 " << res << std::endl;
		mtx.unlock();
		});
	std::thread t10([&]() {
		int res = fibo(r[9]);
		mtx.lock();
		std::cout << "t10:(" << r[9] << ")	  " << res << std::endl;
		mtx.unlock();
		});
	std::thread t11([&]() {
		int res = fibo(r[10]);
		mtx.lock();
		std::cout << "t11:(" << r[10] << ")	   " << res << std::endl;
		mtx.unlock();
		});
	std::thread t12([&]() {
		int res = fibo(r[11]);
		mtx.lock();
		std::cout << "t12:(" << r[11] << ")	    " << res << std::endl;
		mtx.unlock();
		});
	std::thread t13([&]() {
		int res = fibo(r[12]);
		mtx.lock();
		std::cout << "t13:(" << r[12] << ")	    " << res << std::endl;
		mtx.unlock();
		});
	std::thread t14([&]() {
		int res = fibo(r[13]);
		mtx.lock();
		std::cout << "t14:(" << r[13] << ")	    " << res << std::endl;
		mtx.unlock();
		});
	std::thread t15([&]() {
		int res = fibo(r[14]);
		mtx.lock();
		std::cout << "t15:(" << r[14] << ")	    " << res << std::endl;
		mtx.unlock();
		});
	std::thread t16([&]() {
		int res = fibo(r[15]);
		mtx.lock();
		std::cout << "t16:(" << r[15] << ")	    " << res << std::endl;
		mtx.unlock();
		});
	std::thread t17([&]() {
		int res = fibo(r[16]);
		mtx.lock();
		std::cout << "t17:(" << r[16] << ")	    " << res << std::endl;
		mtx.unlock();
		});
	std::thread t18([&]() {
		int res = fibo(r[17]);
		mtx.lock();
		std::cout << "t18:(" << r[17] << ")	    " << res << std::endl;
		mtx.unlock();
		});
	std::thread t19([&]() {
		int res = fibo(r[18]);
		mtx.lock();
		std::cout << "t19:(" << r[18] << ")	    " << res << std::endl;
		mtx.unlock();
		});
	std::thread t20([&]() {
		int res = fibo(r[19]);
		mtx.lock();
		std::cout << "t20:(" << r[19] << ")	    " << res << std::endl;
		mtx.unlock();
		});


	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();
	t10.join();
	t11.join();
	t12.join();
	t13.join();
	t14.join();
	t15.join();
	t16.join();
	t17.join();
	t18.join();
	t19.join();
	t20.join();
}