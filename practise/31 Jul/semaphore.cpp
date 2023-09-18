void writer(){
    while(sem==0)
        sleep(1);
    wait_process()
    //critical sec
    signal();
}