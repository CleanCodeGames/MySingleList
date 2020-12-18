#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

class Timer
{
private:

	using clock_t = high_resolution_clock;
	using second_t = duration<double, ratio<1>>;
	time_point<clock_t> m_beg;

public:

	Timer();
	void reset();
	double elapsed() const;
	~Timer();
};
