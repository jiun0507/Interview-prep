d()){
            if(maximum < (it->first - returns[i].first)){
                ans.clear();
                ans.push_back(make_pair(it->second, i));
            } else if(maximum == it->first - returns[i].first){
                ans.push_back(make_pair(it->second, i));
            } else{
                break;
            }
        }