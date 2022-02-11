    int i1 = -1; 
    int i2 = -1;

    vector<pair<int , int>> checks(5);
    checks[0] = {ask(1 , 2 , 3), 4};
    checks[1] = {ask(1 , 2 , 4), 3};
    checks[2] = {ask(1 , 3 , 4), 2};
    checks[3] = {ask(2 , 3 , 4), 1};

    sort(checks.begin(), checks.end());
    i1 = checks[3].second;
    i2 = checks[2].second;