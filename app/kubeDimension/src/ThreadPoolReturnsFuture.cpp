/*

    kubeVision - OpenCV (part of the KubeVision)
    Modified by: Luc Michalski - 2015
    New features: Web-service and distributed search
    Based on: Find-Object - Mathieu Labbe - IntRoLab - Universite de Sherbrooke
    URL: https://github.com/introlab/find-object

*/

#include <stdio.h>
#include <iostream>
#include <boost/asio.hpp>
#include <thread_pool.h>

int calculateTheAnswerToLifeTheUniverseAndEverything(int i)
{
        boost::this_thread::sleep(boost::posix_time::milliseconds(i));
        std::cout << "Task outputs its argument: " << i << std::endl;
        return i;
}

template <class task_return_t>
void run_item( boost::shared_ptr< boost::packaged_task<task_return_t> > pt)
{
        (*pt)();
}

int main()
{
        int argument = 50;
        int time_to_waist = 100;

        // Lets create a thread_pool
        boost::shared_ptr< thread_pool > tp(new thread_pool(time_to_waist));


        // Will create pt - packaged_task that would bind calculateTheAnswerToLifeTheUniverseAndEverything to some argument
        boost::shared_ptr< boost::packaged_task<int> > pt(new
                boost::packaged_task<int>(
                boost::bind(calculateTheAnswerToLifeTheUniverseAndEverything, argument
                )));

        //Lets get_future from our packaged_task. We can take only unique_future (shared_future does not work correctly on Linux)
        boost::unique_future<int> future= pt->get_future();

        //Lets wrap packaged_task pt to a packaged_task wrapper_pt so that it would return void 
        // We shall always wrap our task into wrappers from which we shall not take any futures.
        boost::shared_ptr< boost::packaged_task<void> > wrapper_pt(new
                boost::packaged_task<void>(boost::bind(run_item<int>, pt)));

        //Lets post our task now
        tp->post(wrapper_pt);

        // Now let's wait all the time needed for our packaged_task pt to be executed
        future.wait();

        std::cout << "Main outputs returned future: " << future.get() << std::endl;

        std::cin.get();
        return 0;
}