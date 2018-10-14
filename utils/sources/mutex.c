/*
 * Copyright 2018 Vladimir Balun
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "winc/utils/multithreading/mutex.h"

#ifdef __unix__

	bool create_mutex(mutex_t* mutex)
	{
		if (pthread_mutex_init(mutex, NULL) == 0)
            return true;
		else
			return false;
	}

	bool mutex_lock(mutex_t* mutex)
	{
		return pthread_mutex_lock(mutex) == 0;
	}

	bool mutex_unlock(mutex_t* mutex)
	{
		return pthread_mutex_unlock(mutex) == 0;
	}

	bool mutex_try_lock(mutex_t* mutex)
	{
		return pthread_mutex_trylock(mutex) == 0;
	}

	bool destroy_mutex(mutex_t* mutex)
	{
		if (pthread_mutex_destroy(mutex) == 0)
            return true;
		else 
			return false;
	}

#elif defined(_WIN32) || defined(WIN32)

	bool create_mutex(mutex_t* mutex)
	{
		if (CreateMutex(0, FALSE, 0))
			return true;
		else
			return false;
	}

	bool mutex_lock(mutex_t* mutex)
	{
		if (mutex)
			return WaitForSingleObject(mutex, INFINITE) != WAIT_OBJECT_0;
		else
			return false;
	}

	bool mutex_unlock(mutex_t* mutex)
	{
		if (mutex)
			return ReleaseMutex(mutex);
		else
			return false;
	}

	bool mutex_try_lock(mutex_t* mutex)
	{
		if (mutex)
			return WaitForSingleObject(mutex, 0) != WAIT_TIMEOUT;
		else
			return false;
	}

	bool destroy_mutex(mutex_t* mutex)
	{
		if (mutex) 
		{
			if (CloseHandle(mutex))
				return true;
			else
				return false;
		}
		else 
		{
			return false;
		}
	}

#endif // _unix__ and WIN32
