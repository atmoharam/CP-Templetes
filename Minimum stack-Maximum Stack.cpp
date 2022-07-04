    cin >> n;
    int G[n + 1 ], S[n + 1 ];

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    stack<int> st;


    // at index i next smaller element in position G[i]
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && a[st.top()] > a[i])st.pop();
        S[i] = st.empty() ? n+1 : st.top();
        st.push(i);
    }

    while (!st.empty())st.pop();

    // at index i next greater element in position G[i]
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && a[st.top()] < a[i])st.pop();
        G[i] = st.empty() ? n+1 : st.top();
        st.push(i);
    }
