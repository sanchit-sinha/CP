d/////////
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = (int)plantTime.size();
        
        auto check = [&](int mid){
            vector<pair<int,int>> v;
            for(int i = 0; i < n; i++){
                int r = (mid - growTime[i]);
                int l = plantTime[i];
                
                v.push_back({r,l});
            }
            
            sort(v.begin(), v.end());
                
            int prev = 0;
            for(int i = 0; i < n; i++){
                int l = v[i].second, r = v[i].first;
                int cur = prev + l - 1;
                
                if(cur >= r) return 0;
                prev = cur + 1;
            }
            
            return 1;
        };
        
        int l = 0, r = 1e9, ans = 0;
        while(l <= r){
            int mid = (l + (r - l)/2);
            if(check(mid)) r = mid - 1, ans = mid;
            else l = mid + 1;
        }
        
        return ans;    
    }




c////////

