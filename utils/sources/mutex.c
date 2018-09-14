#include "winc/utils/multithreading/mutex.h"

#ifdef __unix__

	bool create_mutex(mutex_t* mutex)
	{
		pthread_mutexattr_t attrs;
		pthread_mutexattr_init(&attrs);
		pthread_mutexattr_settype(&attrs, PTHREAD_MUTEX_RECURSIVE);

		if (pthread_mutex_init(mutex, &attrs) != 0)
		{
			SYSTEM_MSG("WINC: Mutex wasn't created...");
			pthread_mutexattr_destroy(&attrs);
			return false;
		}

		pthread_mutexattr_destroy(&attrs);
		return true;
	}

	void mutex_lock(mutex_t* mutex)
	{
		pthread_mutex_lock(mutex);
	}

	void mutex_unlock(mutex_t* mutex)
	{
		pthread_mutex_unlock(mutex);
	}

	bool mutex_try_lock(mutex_t* mutex)
	{
		return pthread_mutex_trylock(mutex) == 0;
	}

	bool destroy_mutex(mutex_t* mutex)
	{
		if (pthread_mutex_destroy(mutex) != 0)
		{
			SYSTEM_MSG("WINC: Mutex wasn't destroyed...");
			return false;
		}

		return true;
	}

#elif defined(_WIN32) || defined(WIN32)

	bool create_mutex(mutex_t* mutex)
	{
		if (CreateMutex(0, FALSE, 0))
			return true;

		PRINT_LAST_SYSTEM_ERROR();
		return false;
	}

	void mutex_lock(mutex_t* mutex)
	{
		if (WaitForSingleObject(mutex, INFINITE) == WAIT_FAILED)
			PRINT_LAST_SYSTEM_ERROR();
	}

	void mutex_unlock(mutex_t* mutex)
	{
		if (!ReleaseMutex(mutex))
			PRINT_LAST_SYSTEM_ERROR();
	}

	bool mutex_try_lock(mutex_t* mutex)
	{
		return WaitForSingleObject(mutex, 0) != WAIT_TIMEOUT;
	}

	bool destroy_mutex(mutex_t* mutex)
	{
		if (CloseHandle(mutex))
			return true;

		PRINT_LAST_SYSTEM_ERROR();
		return false;
	}

#endif // _unix__ and WIN32
