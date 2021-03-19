
    cin>>a>>b;
    while(t--){
        bool result = set2();
        if(writeFile.is_open()){
            writeFile<<"result:"<<to_string(result)<<"\n";
            // writeFile.close();
        }   
        if(!result){
            return 0;
        }
    }