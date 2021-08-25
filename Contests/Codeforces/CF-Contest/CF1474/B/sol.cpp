#include "bits/stdc++.h"
using namespace std;
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define pb push_back
#define ll long long
#define ld long double
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c.size())
#define mp make_pair
#define mt make_tuple
#define get(x,c) get<x>(c)
#define trav(a,x) for(auto a=x.begin();a!=x.end();a++)
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORR(i,b,a) for(int i=b;i>=a;i--)
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpll vector<pll>
#define f first
#define s second

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll power(ll x,ll ex);
ll powermod(ll x,ll ex,ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e5+11;

vll v;

void solve(){
    ll n;
    cin >> n;     

    ll a = 0 ,b = 0;
    auto it = lb(all(v) , 1 + n);
    a = *it;

    it = lb(all(v) , a + n);
    b = *it;

    // cout << a <<" " << b <<"\n";
    cout << a*b <<"\n";
}

int main(){
    IOS;
    cout<<fixed<<setprecision(20);
    
    ll mx = 2264;
    ll a[mx][3] = {1, 2, 2,
2, 3, 1,
3, 5, 2,
4, 7, 2,
5, 11, 4,
6, 13, 2,
7, 17, 4,
8, 19, 2,
9, 23, 4,
10, 29, 6,
11, 31, 2,
12, 37, 6,
13, 41, 4,
14, 43, 2,
15, 47, 4,
16, 53, 6,
17, 59, 6,
18, 61, 2,
19, 67, 6,
20, 71, 4,
21, 73, 2,
22, 79, 6,
23, 83, 4,
24, 89, 6,
25, 97, 8,
26, 101, 4,
27, 103, 2,
28, 107, 4,
29, 109, 2,
30, 113, 4,
31, 127, 14,
32, 131, 4,
33, 137, 6,
34, 139, 2,
35, 149, 10,
36, 151, 2,
37, 157, 6,
38, 163, 6,
39, 167, 4,
40, 173, 6,
41, 179, 6,
42, 181, 2,
43, 191, 10,
44, 193, 2,
45, 197, 4,
46, 199, 2,
47, 211, 12,
48, 223, 12,
49, 227, 4,
50, 229, 2,
51, 233, 4,
52, 239, 6,
53, 241, 2,
54, 251, 10,
55, 257, 6,
56, 263, 6,
57, 269, 6,
58, 271, 2,
59, 277, 6,
60, 281, 4,
61, 283, 2,
62, 293, 10,
63, 307, 14,
64, 311, 4,
65, 313, 2,
66, 317, 4,
67, 331, 14,
68, 337, 6,
69, 347, 10,
70, 349, 2,
71, 353, 4,
72, 359, 6,
73, 367, 8,
74, 373, 6,
75, 379, 6,
76, 383, 4,
77, 389, 6,
78, 397, 8,
79, 401, 4,
80, 409, 8,
81, 419, 10,
82, 421, 2,
83, 431, 10,
84, 433, 2,
85, 439, 6,
86, 443, 4,
87, 449, 6,
88, 457, 8,
89, 461, 4,
90, 463, 2,
91, 467, 4,
92, 479, 12,
93, 487, 8,
94, 491, 4,
95, 499, 8,
96, 503, 4,
97, 509, 6,
98, 521, 12,
99, 523, 2,
100, 541, 18,
101, 547, 6,
102, 557, 10,
103, 563, 6,
104, 569, 6,
105, 571, 2,
106, 577, 6,
107, 587, 10,
108, 593, 6,
109, 599, 6,
110, 601, 2,
111, 607, 6,
112, 613, 6,
113, 617, 4,
114, 619, 2,
115, 631, 12,
116, 641, 10,
117, 643, 2,
118, 647, 4,
119, 653, 6,
120, 659, 6,
121, 661, 2,
122, 673, 12,
123, 677, 4,
124, 683, 6,
125, 691, 8,
126, 701, 10,
127, 709, 8,
128, 719, 10,
129, 727, 8,
130, 733, 6,
131, 739, 6,
132, 743, 4,
133, 751, 8,
134, 757, 6,
135, 761, 4,
136, 769, 8,
137, 773, 4,
138, 787, 14,
139, 797, 10,
140, 809, 12,
141, 811, 2,
142, 821, 10,
143, 823, 2,
144, 827, 4,
145, 829, 2,
146, 839, 10,
147, 853, 14,
148, 857, 4,
149, 859, 2,
150, 863, 4,
151, 877, 14,
152, 881, 4,
153, 883, 2,
154, 887, 4,
155, 907, 20,
156, 911, 4,
157, 919, 8,
158, 929, 10,
159, 937, 8,
160, 941, 4,
161, 947, 6,
162, 953, 6,
163, 967, 14,
164, 971, 4,
165, 977, 6,
166, 983, 6,
167, 991, 8,
168, 997, 6,
169, 1009, 12,
170, 1013, 4,
171, 1019, 6,
172, 1021, 2,
173, 1031, 10,
174, 1033, 2,
175, 1039, 6,
176, 1049, 10,
177, 1051, 2,
178, 1061, 10,
179, 1063, 2,
180, 1069, 6,
181, 1087, 18,
182, 1091, 4,
183, 1093, 2,
184, 1097, 4,
185, 1103, 6,
186, 1109, 6,
187, 1117, 8,
188, 1123, 6,
189, 1129, 6,
190, 1151, 22,
191, 1153, 2,
192, 1163, 10,
193, 1171, 8,
194, 1181, 10,
195, 1187, 6,
196, 1193, 6,
197, 1201, 8,
198, 1213, 12,
199, 1217, 4,
200, 1223, 6,
201, 1229, 6,
202, 1231, 2,
203, 1237, 6,
204, 1249, 12,
205, 1259, 10,
206, 1277, 18,
207, 1279, 2,
208, 1283, 4,
209, 1289, 6,
210, 1291, 2,
211, 1297, 6,
212, 1301, 4,
213, 1303, 2,
214, 1307, 4,
215, 1319, 12,
216, 1321, 2,
217, 1327, 6,
218, 1361, 34,
219, 1367, 6,
220, 1373, 6,
221, 1381, 8,
222, 1399, 18,
223, 1409, 10,
224, 1423, 14,
225, 1427, 4,
226, 1429, 2,
227, 1433, 4,
228, 1439, 6,
229, 1447, 8,
230, 1451, 4,
231, 1453, 2,
232, 1459, 6,
233, 1471, 12,
234, 1481, 10,
235, 1483, 2,
236, 1487, 4,
237, 1489, 2,
238, 1493, 4,
239, 1499, 6,
240, 1511, 12,
241, 1523, 12,
242, 1531, 8,
243, 1543, 12,
244, 1549, 6,
245, 1553, 4,
246, 1559, 6,
247, 1567, 8,
248, 1571, 4,
249, 1579, 8,
250, 1583, 4,
251, 1597, 14,
252, 1601, 4,
253, 1607, 6,
254, 1609, 2,
255, 1613, 4,
256, 1619, 6,
257, 1621, 2,
258, 1627, 6,
259, 1637, 10,
260, 1657, 20,
261, 1663, 6,
262, 1667, 4,
263, 1669, 2,
264, 1693, 24,
265, 1697, 4,
266, 1699, 2,
267, 1709, 10,
268, 1721, 12,
269, 1723, 2,
270, 1733, 10,
271, 1741, 8,
272, 1747, 6,
273, 1753, 6,
274, 1759, 6,
275, 1777, 18,
276, 1783, 6,
277, 1787, 4,
278, 1789, 2,
279, 1801, 12,
280, 1811, 10,
281, 1823, 12,
282, 1831, 8,
283, 1847, 16,
284, 1861, 14,
285, 1867, 6,
286, 1871, 4,
287, 1873, 2,
288, 1877, 4,
289, 1879, 2,
290, 1889, 10,
291, 1901, 12,
292, 1907, 6,
293, 1913, 6,
294, 1931, 18,
295, 1933, 2,
296, 1949, 16,
297, 1951, 2,
298, 1973, 22,
299, 1979, 6,
300, 1987, 8,
301, 1993, 6,
302, 1997, 4,
303, 1999, 2,
304, 2003, 4,
305, 2011, 8,
306, 2017, 6,
307, 2027, 10,
308, 2029, 2,
309, 2039, 10,
310, 2053, 14,
311, 2063, 10,
312, 2069, 6,
313, 2081, 12,
314, 2083, 2,
315, 2087, 4,
316, 2089, 2,
317, 2099, 10,
318, 2111, 12,
319, 2113, 2,
320, 2129, 16,
321, 2131, 2,
322, 2137, 6,
323, 2141, 4,
324, 2143, 2,
325, 2153, 10,
326, 2161, 8,
327, 2179, 18,
328, 2203, 24,
329, 2207, 4,
330, 2213, 6,
331, 2221, 8,
332, 2237, 16,
333, 2239, 2,
334, 2243, 4,
335, 2251, 8,
336, 2267, 16,
337, 2269, 2,
338, 2273, 4,
339, 2281, 8,
340, 2287, 6,
341, 2293, 6,
342, 2297, 4,
343, 2309, 12,
344, 2311, 2,
345, 2333, 22,
346, 2339, 6,
347, 2341, 2,
348, 2347, 6,
349, 2351, 4,
350, 2357, 6,
351, 2371, 14,
352, 2377, 6,
353, 2381, 4,
354, 2383, 2,
355, 2389, 6,
356, 2393, 4,
357, 2399, 6,
358, 2411, 12,
359, 2417, 6,
360, 2423, 6,
361, 2437, 14,
362, 2441, 4,
363, 2447, 6,
364, 2459, 12,
365, 2467, 8,
366, 2473, 6,
367, 2477, 4,
368, 2503, 26,
369, 2521, 18,
370, 2531, 10,
371, 2539, 8,
372, 2543, 4,
373, 2549, 6,
374, 2551, 2,
375, 2557, 6,
376, 2579, 22,
377, 2591, 12,
378, 2593, 2,
379, 2609, 16,
380, 2617, 8,
381, 2621, 4,
382, 2633, 12,
383, 2647, 14,
384, 2657, 10,
385, 2659, 2,
386, 2663, 4,
387, 2671, 8,
388, 2677, 6,
389, 2683, 6,
390, 2687, 4,
391, 2689, 2,
392, 2693, 4,
393, 2699, 6,
394, 2707, 8,
395, 2711, 4,
396, 2713, 2,
397, 2719, 6,
398, 2729, 10,
399, 2731, 2,
400, 2741, 10,
401, 2749, 8,
402, 2753, 4,
403, 2767, 14,
404, 2777, 10,
405, 2789, 12,
406, 2791, 2,
407, 2797, 6,
408, 2801, 4,
409, 2803, 2,
410, 2819, 16,
411, 2833, 14,
412, 2837, 4,
413, 2843, 6,
414, 2851, 8,
415, 2857, 6,
416, 2861, 4,
417, 2879, 18,
418, 2887, 8,
419, 2897, 10,
420, 2903, 6,
421, 2909, 6,
422, 2917, 8,
423, 2927, 10,
424, 2939, 12,
425, 2953, 14,
426, 2957, 4,
427, 2963, 6,
428, 2969, 6,
429, 2971, 2,
430, 2999, 28,
431, 3001, 2,
432, 3011, 10,
433, 3019, 8,
434, 3023, 4,
435, 3037, 14,
436, 3041, 4,
437, 3049, 8,
438, 3061, 12,
439, 3067, 6,
440, 3079, 12,
441, 3083, 4,
442, 3089, 6,
443, 3109, 20,
444, 3119, 10,
445, 3121, 2,
446, 3137, 16,
447, 3163, 26,
448, 3167, 4,
449, 3169, 2,
450, 3181, 12,
451, 3187, 6,
452, 3191, 4,
453, 3203, 12,
454, 3209, 6,
455, 3217, 8,
456, 3221, 4,
457, 3229, 8,
458, 3251, 22,
459, 3253, 2,
460, 3257, 4,
461, 3259, 2,
462, 3271, 12,
463, 3299, 28,
464, 3301, 2,
465, 3307, 6,
466, 3313, 6,
467, 3319, 6,
468, 3323, 4,
469, 3329, 6,
470, 3331, 2,
471, 3343, 12,
472, 3347, 4,
473, 3359, 12,
474, 3361, 2,
475, 3371, 10,
476, 3373, 2,
477, 3389, 16,
478, 3391, 2,
479, 3407, 16,
480, 3413, 6,
481, 3433, 20,
482, 3449, 16,
483, 3457, 8,
484, 3461, 4,
485, 3463, 2,
486, 3467, 4,
487, 3469, 2,
488, 3491, 22,
489, 3499, 8,
490, 3511, 12,
491, 3517, 6,
492, 3527, 10,
493, 3529, 2,
494, 3533, 4,
495, 3539, 6,
496, 3541, 2,
497, 3547, 6,
498, 3557, 10,
499, 3559, 2,
500, 3571, 12,
501, 3581, 10,
502, 3583, 2,
503, 3593, 10,
504, 3607, 14,
505, 3613, 6,
506, 3617, 4,
507, 3623, 6,
508, 3631, 8,
509, 3637, 6,
510, 3643, 6,
511, 3659, 16,
512, 3671, 12,
513, 3673, 2,
514, 3677, 4,
515, 3691, 14,
516, 3697, 6,
517, 3701, 4,
518, 3709, 8,
519, 3719, 10,
520, 3727, 8,
521, 3733, 6,
522, 3739, 6,
523, 3761, 22,
524, 3767, 6,
525, 3769, 2,
526, 3779, 10,
527, 3793, 14,
528, 3797, 4,
529, 3803, 6,
530, 3821, 18,
531, 3823, 2,
532, 3833, 10,
533, 3847, 14,
534, 3851, 4,
535, 3853, 2,
536, 3863, 10,
537, 3877, 14,
538, 3881, 4,
539, 3889, 8,
540, 3907, 18,
541, 3911, 4,
542, 3917, 6,
543, 3919, 2,
544, 3923, 4,
545, 3929, 6,
546, 3931, 2,
547, 3943, 12,
548, 3947, 4,
549, 3967, 20,
550, 3989, 22,
551, 4001, 12,
552, 4003, 2,
553, 4007, 4,
554, 4013, 6,
555, 4019, 6,
556, 4021, 2,
557, 4027, 6,
558, 4049, 22,
559, 4051, 2,
560, 4057, 6,
561, 4073, 16,
562, 4079, 6,
563, 4091, 12,
564, 4093, 2,
565, 4099, 6,
566, 4111, 12,
567, 4127, 16,
568, 4129, 2,
569, 4133, 4,
570, 4139, 6,
571, 4153, 14,
572, 4157, 4,
573, 4159, 2,
574, 4177, 18,
575, 4201, 24,
576, 4211, 10,
577, 4217, 6,
578, 4219, 2,
579, 4229, 10,
580, 4231, 2,
581, 4241, 10,
582, 4243, 2,
583, 4253, 10,
584, 4259, 6,
585, 4261, 2,
586, 4271, 10,
587, 4273, 2,
588, 4283, 10,
589, 4289, 6,
590, 4297, 8,
591, 4327, 30,
592, 4337, 10,
593, 4339, 2,
594, 4349, 10,
595, 4357, 8,
596, 4363, 6,
597, 4373, 10,
598, 4391, 18,
599, 4397, 6,
600, 4409, 12,
601, 4421, 12,
602, 4423, 2,
603, 4441, 18,
604, 4447, 6,
605, 4451, 4,
606, 4457, 6,
607, 4463, 6,
608, 4481, 18,
609, 4483, 2,
610, 4493, 10,
611, 4507, 14,
612, 4513, 6,
613, 4517, 4,
614, 4519, 2,
615, 4523, 4,
616, 4547, 24,
617, 4549, 2,
618, 4561, 12,
619, 4567, 6,
620, 4583, 16,
621, 4591, 8,
622, 4597, 6,
623, 4603, 6,
624, 4621, 18,
625, 4637, 16,
626, 4639, 2,
627, 4643, 4,
628, 4649, 6,
629, 4651, 2,
630, 4657, 6,
631, 4663, 6,
632, 4673, 10,
633, 4679, 6,
634, 4691, 12,
635, 4703, 12,
636, 4721, 18,
637, 4723, 2,
638, 4729, 6,
639, 4733, 4,
640, 4751, 18,
641, 4759, 8,
642, 4783, 24,
643, 4787, 4,
644, 4789, 2,
645, 4793, 4,
646, 4799, 6,
647, 4801, 2,
648, 4813, 12,
649, 4817, 4,
650, 4831, 14,
651, 4861, 30,
652, 4871, 10,
653, 4877, 6,
654, 4889, 12,
655, 4903, 14,
656, 4909, 6,
657, 4919, 10,
658, 4931, 12,
659, 4933, 2,
660, 4937, 4,
661, 4943, 6,
662, 4951, 8,
663, 4957, 6,
664, 4967, 10,
665, 4969, 2,
666, 4973, 4,
667, 4987, 14,
668, 4993, 6,
669, 4999, 6,
670, 5003, 4,
671, 5009, 6,
672, 5011, 2,
673, 5021, 10,
674, 5023, 2,
675, 5039, 16,
676, 5051, 12,
677, 5059, 8,
678, 5077, 18,
679, 5081, 4,
680, 5087, 6,
681, 5099, 12,
682, 5101, 2,
683, 5107, 6,
684, 5113, 6,
685, 5119, 6,
686, 5147, 28,
687, 5153, 6,
688, 5167, 14,
689, 5171, 4,
690, 5179, 8,
691, 5189, 10,
692, 5197, 8,
693, 5209, 12,
694, 5227, 18,
695, 5231, 4,
696, 5233, 2,
697, 5237, 4,
698, 5261, 24,
699, 5273, 12,
700, 5279, 6,
701, 5281, 2,
702, 5297, 16,
703, 5303, 6,
704, 5309, 6,
705, 5323, 14,
706, 5333, 10,
707, 5347, 14,
708, 5351, 4,
709, 5381, 30,
710, 5387, 6,
711, 5393, 6,
712, 5399, 6,
713, 5407, 8,
714, 5413, 6,
715, 5417, 4,
716, 5419, 2,
717, 5431, 12,
718, 5437, 6,
719, 5441, 4,
720, 5443, 2,
721, 5449, 6,
722, 5471, 22,
723, 5477, 6,
724, 5479, 2,
725, 5483, 4,
726, 5501, 18,
727, 5503, 2,
728, 5507, 4,
729, 5519, 12,
730, 5521, 2,
731, 5527, 6,
732, 5531, 4,
733, 5557, 26,
734, 5563, 6,
735, 5569, 6,
736, 5573, 4,
737, 5581, 8,
738, 5591, 10,
739, 5623, 32,
740, 5639, 16,
741, 5641, 2,
742, 5647, 6,
743, 5651, 4,
744, 5653, 2,
745, 5657, 4,
746, 5659, 2,
747, 5669, 10,
748, 5683, 14,
749, 5689, 6,
750, 5693, 4,
751, 5701, 8,
752, 5711, 10,
753, 5717, 6,
754, 5737, 20,
755, 5741, 4,
756, 5743, 2,
757, 5749, 6,
758, 5779, 30,
759, 5783, 4,
760, 5791, 8,
761, 5801, 10,
762, 5807, 6,
763, 5813, 6,
764, 5821, 8,
765, 5827, 6,
766, 5839, 12,
767, 5843, 4,
768, 5849, 6,
769, 5851, 2,
770, 5857, 6,
771, 5861, 4,
772, 5867, 6,
773, 5869, 2,
774, 5879, 10,
775, 5881, 2,
776, 5897, 16,
777, 5903, 6,
778, 5923, 20,
779, 5927, 4,
780, 5939, 12,
781, 5953, 14,
782, 5981, 28,
783, 5987, 6,
784, 6007, 20,
785, 6011, 4,
786, 6029, 18,
787, 6037, 8,
788, 6043, 6,
789, 6047, 4,
790, 6053, 6,
791, 6067, 14,
792, 6073, 6,
793, 6079, 6,
794, 6089, 10,
795, 6091, 2,
796, 6101, 10,
797, 6113, 12,
798, 6121, 8,
799, 6131, 10,
800, 6133, 2,
801, 6143, 10,
802, 6151, 8,
803, 6163, 12,
804, 6173, 10,
805, 6197, 24,
806, 6199, 2,
807, 6203, 4,
808, 6211, 8,
809, 6217, 6,
810, 6221, 4,
811, 6229, 8,
812, 6247, 18,
813, 6257, 10,
814, 6263, 6,
815, 6269, 6,
816, 6271, 2,
817, 6277, 6,
818, 6287, 10,
819, 6299, 12,
820, 6301, 2,
821, 6311, 10,
822, 6317, 6,
823, 6323, 6,
824, 6329, 6,
825, 6337, 8,
826, 6343, 6,
827, 6353, 10,
828, 6359, 6,
829, 6361, 2,
830, 6367, 6,
831, 6373, 6,
832, 6379, 6,
833, 6389, 10,
834, 6397, 8,
835, 6421, 24,
836, 6427, 6,
837, 6449, 22,
838, 6451, 2,
839, 6469, 18,
840, 6473, 4,
841, 6481, 8,
842, 6491, 10,
843, 6521, 30,
844, 6529, 8,
845, 6547, 18,
846, 6551, 4,
847, 6553, 2,
848, 6563, 10,
849, 6569, 6,
850, 6571, 2,
851, 6577, 6,
852, 6581, 4,
853, 6599, 18,
854, 6607, 8,
855, 6619, 12,
856, 6637, 18,
857, 6653, 16,
858, 6659, 6,
859, 6661, 2,
860, 6673, 12,
861, 6679, 6,
862, 6689, 10,
863, 6691, 2,
864, 6701, 10,
865, 6703, 2,
866, 6709, 6,
867, 6719, 10,
868, 6733, 14,
869, 6737, 4,
870, 6761, 24,
871, 6763, 2,
872, 6779, 16,
873, 6781, 2,
874, 6791, 10,
875, 6793, 2,
876, 6803, 10,
877, 6823, 20,
878, 6827, 4,
879, 6829, 2,
880, 6833, 4,
881, 6841, 8,
882, 6857, 16,
883, 6863, 6,
884, 6869, 6,
885, 6871, 2,
886, 6883, 12,
887, 6899, 16,
888, 6907, 8,
889, 6911, 4,
890, 6917, 6,
891, 6947, 30,
892, 6949, 2,
893, 6959, 10,
894, 6961, 2,
895, 6967, 6,
896, 6971, 4,
897, 6977, 6,
898, 6983, 6,
899, 6991, 8,
900, 6997, 6,
901, 7001, 4,
902, 7013, 12,
903, 7019, 6,
904, 7027, 8,
905, 7039, 12,
906, 7043, 4,
907, 7057, 14,
908, 7069, 12,
909, 7079, 10,
910, 7103, 24,
911, 7109, 6,
912, 7121, 12,
913, 7127, 6,
914, 7129, 2,
915, 7151, 22,
916, 7159, 8,
917, 7177, 18,
918, 7187, 10,
919, 7193, 6,
920, 7207, 14,
921, 7211, 4,
922, 7213, 2,
923, 7219, 6,
924, 7229, 10,
925, 7237, 8,
926, 7243, 6,
927, 7247, 4,
928, 7253, 6,
929, 7283, 30,
930, 7297, 14,
931, 7307, 10,
932, 7309, 2,
933, 7321, 12,
934, 7331, 10,
935, 7333, 2,
936, 7349, 16,
937, 7351, 2,
938, 7369, 18,
939, 7393, 24,
940, 7411, 18,
941, 7417, 6,
942, 7433, 16,
943, 7451, 18,
944, 7457, 6,
945, 7459, 2,
946, 7477, 18,
947, 7481, 4,
948, 7487, 6,
949, 7489, 2,
950, 7499, 10,
951, 7507, 8,
952, 7517, 10,
953, 7523, 6,
954, 7529, 6,
955, 7537, 8,
956, 7541, 4,
957, 7547, 6,
958, 7549, 2,
959, 7559, 10,
960, 7561, 2,
961, 7573, 12,
962, 7577, 4,
963, 7583, 6,
964, 7589, 6,
965, 7591, 2,
966, 7603, 12,
967, 7607, 4,
968, 7621, 14,
969, 7639, 18,
970, 7643, 4,
971, 7649, 6,
972, 7669, 20,
973, 7673, 4,
974, 7681, 8,
975, 7687, 6,
976, 7691, 4,
977, 7699, 8,
978, 7703, 4,
979, 7717, 14,
980, 7723, 6,
981, 7727, 4,
982, 7741, 14,
983, 7753, 12,
984, 7757, 4,
985, 7759, 2,
986, 7789, 30,
987, 7793, 4,
988, 7817, 24,
989, 7823, 6,
990, 7829, 6,
991, 7841, 12,
992, 7853, 12,
993, 7867, 14,
994, 7873, 6,
995, 7877, 4,
996, 7879, 2,
997, 7883, 4,
998, 7901, 18,
999, 7907, 6,
1000, 7919, 12,
1001, 7927, 8,
1002, 7933, 6,
1003, 7937, 4,
1004, 7949, 12,
1005, 7951, 2,
1006, 7963, 12,
1007, 7993, 30,
1008, 8009, 16,
1009, 8011, 2,
1010, 8017, 6,
1011, 8039, 22,
1012, 8053, 14,
1013, 8059, 6,
1014, 8069, 10,
1015, 8081, 12,
1016, 8087, 6,
1017, 8089, 2,
1018, 8093, 4,
1019, 8101, 8,
1020, 8111, 10,
1021, 8117, 6,
1022, 8123, 6,
1023, 8147, 24,
1024, 8161, 14,
1025, 8167, 6,
1026, 8171, 4,
1027, 8179, 8,
1028, 8191, 12,
1029, 8209, 18,
1030, 8219, 10,
1031, 8221, 2,
1032, 8231, 10,
1033, 8233, 2,
1034, 8237, 4,
1035, 8243, 6,
1036, 8263, 20,
1037, 8269, 6,
1038, 8273, 4,
1039, 8287, 14,
1040, 8291, 4,
1041, 8293, 2,
1042, 8297, 4,
1043, 8311, 14,
1044, 8317, 6,
1045, 8329, 12,
1046, 8353, 24,
1047, 8363, 10,
1048, 8369, 6,
1049, 8377, 8,
1050, 8387, 10,
1051, 8389, 2,
1052, 8419, 30,
1053, 8423, 4,
1054, 8429, 6,
1055, 8431, 2,
1056, 8443, 12,
1057, 8447, 4,
1058, 8461, 14,
1059, 8467, 6,
1060, 8501, 34,
1061, 8513, 12,
1062, 8521, 8,
1063, 8527, 6,
1064, 8537, 10,
1065, 8539, 2,
1066, 8543, 4,
1067, 8563, 20,
1068, 8573, 10,
1069, 8581, 8,
1070, 8597, 16,
1071, 8599, 2,
1072, 8609, 10,
1073, 8623, 14,
1074, 8627, 4,
1075, 8629, 2,
1076, 8641, 12,
1077, 8647, 6,
1078, 8663, 16,
1079, 8669, 6,
1080, 8677, 8,
1081, 8681, 4,
1082, 8689, 8,
1083, 8693, 4,
1084, 8699, 6,
1085, 8707, 8,
1086, 8713, 6,
1087, 8719, 6,
1088, 8731, 12,
1089, 8737, 6,
1090, 8741, 4,
1091, 8747, 6,
1092, 8753, 6,
1093, 8761, 8,
1094, 8779, 18,
1095, 8783, 4,
1096, 8803, 20,
1097, 8807, 4,
1098, 8819, 12,
1099, 8821, 2,
1100, 8831, 10,
1101, 8837, 6,
1102, 8839, 2,
1103, 8849, 10,
1104, 8861, 12,
1105, 8863, 2,
1106, 8867, 4,
1107, 8887, 20,
1108, 8893, 6,
1109, 8923, 30,
1110, 8929, 6,
1111, 8933, 4,
1112, 8941, 8,
1113, 8951, 10,
1114, 8963, 12,
1115, 8969, 6,
1116, 8971, 2,
1117, 8999, 28,
1118, 9001, 2,
1119, 9007, 6,
1120, 9011, 4,
1121, 9013, 2,
1122, 9029, 16,
1123, 9041, 12,
1124, 9043, 2,
1125, 9049, 6,
1126, 9059, 10,
1127, 9067, 8,
1128, 9091, 24,
1129, 9103, 12,
1130, 9109, 6,
1131, 9127, 18,
1132, 9133, 6,
1133, 9137, 4,
1134, 9151, 14,
1135, 9157, 6,
1136, 9161, 4,
1137, 9173, 12,
1138, 9181, 8,
1139, 9187, 6,
1140, 9199, 12,
1141, 9203, 4,
1142, 9209, 6,
1143, 9221, 12,
1144, 9227, 6,
1145, 9239, 12,
1146, 9241, 2,
1147, 9257, 16,
1148, 9277, 20,
1149, 9281, 4,
1150, 9283, 2,
1151, 9293, 10,
1152, 9311, 18,
1153, 9319, 8,
1154, 9323, 4,
1155, 9337, 14,
1156, 9341, 4,
1157, 9343, 2,
1158, 9349, 6,
1159, 9371, 22,
1160, 9377, 6,
1161, 9391, 14,
1162, 9397, 6,
1163, 9403, 6,
1164, 9413, 10,
1165, 9419, 6,
1166, 9421, 2,
1167, 9431, 10,
1168, 9433, 2,
1169, 9437, 4,
1170, 9439, 2,
1171, 9461, 22,
1172, 9463, 2,
1173, 9467, 4,
1174, 9473, 6,
1175, 9479, 6,
1176, 9491, 12,
1177, 9497, 6,
1178, 9511, 14,
1179, 9521, 10,
1180, 9533, 12,
1181, 9539, 6,
1182, 9547, 8,
1183, 9551, 4,
1184, 9587, 36,
1185, 9601, 14,
1186, 9613, 12,
1187, 9619, 6,
1188, 9623, 4,
1189, 9629, 6,
1190, 9631, 2,
1191, 9643, 12,
1192, 9649, 6,
1193, 9661, 12,
1194, 9677, 16,
1195, 9679, 2,
1196, 9689, 10,
1197, 9697, 8,
1198, 9719, 22,
1199, 9721, 2,
1200, 9733, 12,
1201, 9739, 6,
1202, 9743, 4,
1203, 9749, 6,
1204, 9767, 18,
1205, 9769, 2,
1206, 9781, 12,
1207, 9787, 6,
1208, 9791, 4,
1209, 9803, 12,
1210, 9811, 8,
1211, 9817, 6,
1212, 9829, 12,
1213, 9833, 4,
1214, 9839, 6,
1215, 9851, 12,
1216, 9857, 6,
1217, 9859, 2,
1218, 9871, 12,
1219, 9883, 12,
1220, 9887, 4,
1221, 9901, 14,
1222, 9907, 6,
1223, 9923, 16,
1224, 9929, 6,
1225, 9931, 2,
1226, 9941, 10,
1227, 9949, 8,
1228, 9967, 18,
1229, 9973, 6,
1230, 10007, 34,
1231, 10009, 2,
1232, 10037, 28,
1233, 10039, 2,
1234, 10061, 22,
1235, 10067, 6,
1236, 10069, 2,
1237, 10079, 10,
1238, 10091, 12,
1239, 10093, 2,
1240, 10099, 6,
1241, 10103, 4,
1242, 10111, 8,
1243, 10133, 22,
1244, 10139, 6,
1245, 10141, 2,
1246, 10151, 10,
1247, 10159, 8,
1248, 10163, 4,
1249, 10169, 6,
1250, 10177, 8,
1251, 10181, 4,
1252, 10193, 12,
1253, 10211, 18,
1254, 10223, 12,
1255, 10243, 20,
1256, 10247, 4,
1257, 10253, 6,
1258, 10259, 6,
1259, 10267, 8,
1260, 10271, 4,
1261, 10273, 2,
1262, 10289, 16,
1263, 10301, 12,
1264, 10303, 2,
1265, 10313, 10,
1266, 10321, 8,
1267, 10331, 10,
1268, 10333, 2,
1269, 10337, 4,
1270, 10343, 6,
1271, 10357, 14,
1272, 10369, 12,
1273, 10391, 22,
1274, 10399, 8,
1275, 10427, 28,
1276, 10429, 2,
1277, 10433, 4,
1278, 10453, 20,
1279, 10457, 4,
1280, 10459, 2,
1281, 10463, 4,
1282, 10477, 14,
1283, 10487, 10,
1284, 10499, 12,
1285, 10501, 2,
1286, 10513, 12,
1287, 10529, 16,
1288, 10531, 2,
1289, 10559, 28,
1290, 10567, 8,
1291, 10589, 22,
1292, 10597, 8,
1293, 10601, 4,
1294, 10607, 6,
1295, 10613, 6,
1296, 10627, 14,
1297, 10631, 4,
1298, 10639, 8,
1299, 10651, 12,
1300, 10657, 6,
1301, 10663, 6,
1302, 10667, 4,
1303, 10687, 20,
1304, 10691, 4,
1305, 10709, 18,
1306, 10711, 2,
1307, 10723, 12,
1308, 10729, 6,
1309, 10733, 4,
1310, 10739, 6,
1311, 10753, 14,
1312, 10771, 18,
1313, 10781, 10,
1314, 10789, 8,
1315, 10799, 10,
1316, 10831, 32,
1317, 10837, 6,
1318, 10847, 10,
1319, 10853, 6,
1320, 10859, 6,
1321, 10861, 2,
1322, 10867, 6,
1323, 10883, 16,
1324, 10889, 6,
1325, 10891, 2,
1326, 10903, 12,
1327, 10909, 6,
1328, 10937, 28,
1329, 10939, 2,
1330, 10949, 10,
1331, 10957, 8,
1332, 10973, 16,
1333, 10979, 6,
1334, 10987, 8,
1335, 10993, 6,
1336, 11003, 10,
1337, 11027, 24,
1338, 11047, 20,
1339, 11057, 10,
1340, 11059, 2,
1341, 11069, 10,
1342, 11071, 2,
1343, 11083, 12,
1344, 11087, 4,
1345, 11093, 6,
1346, 11113, 20,
1347, 11117, 4,
1348, 11119, 2,
1349, 11131, 12,
1350, 11149, 18,
1351, 11159, 10,
1352, 11161, 2,
1353, 11171, 10,
1354, 11173, 2,
1355, 11177, 4,
1356, 11197, 20,
1357, 11213, 16,
1358, 11239, 26,
1359, 11243, 4,
1360, 11251, 8,
1361, 11257, 6,
1362, 11261, 4,
1363, 11273, 12,
1364, 11279, 6,
1365, 11287, 8,
1366, 11299, 12,
1367, 11311, 12,
1368, 11317, 6,
1369, 11321, 4,
1370, 11329, 8,
1371, 11351, 22,
1372, 11353, 2,
1373, 11369, 16,
1374, 11383, 14,
1375, 11393, 10,
1376, 11399, 6,
1377, 11411, 12,
1378, 11423, 12,
1379, 11437, 14,
1380, 11443, 6,
1381, 11447, 4,
1382, 11467, 20,
1383, 11471, 4,
1384, 11483, 12,
1385, 11489, 6,
1386, 11491, 2,
1387, 11497, 6,
1388, 11503, 6,
1389, 11519, 16,
1390, 11527, 8,
1391, 11549, 22,
1392, 11551, 2,
1393, 11579, 28,
1394, 11587, 8,
1395, 11593, 6,
1396, 11597, 4,
1397, 11617, 20,
1398, 11621, 4,
1399, 11633, 12,
1400, 11657, 24,
1401, 11677, 20,
1402, 11681, 4,
1403, 11689, 8,
1404, 11699, 10,
1405, 11701, 2,
1406, 11717, 16,
1407, 11719, 2,
1408, 11731, 12,
1409, 11743, 12,
1410, 11777, 34,
1411, 11779, 2,
1412, 11783, 4,
1413, 11789, 6,
1414, 11801, 12,
1415, 11807, 6,
1416, 11813, 6,
1417, 11821, 8,
1418, 11827, 6,
1419, 11831, 4,
1420, 11833, 2,
1421, 11839, 6,
1422, 11863, 24,
1423, 11867, 4,
1424, 11887, 20,
1425, 11897, 10,
1426, 11903, 6,
1427, 11909, 6,
1428, 11923, 14,
1429, 11927, 4,
1430, 11933, 6,
1431, 11939, 6,
1432, 11941, 2,
1433, 11953, 12,
1434, 11959, 6,
1435, 11969, 10,
1436, 11971, 2,
1437, 11981, 10,
1438, 11987, 6,
1439, 12007, 20,
1440, 12011, 4,
1441, 12037, 26,
1442, 12041, 4,
1443, 12043, 2,
1444, 12049, 6,
1445, 12071, 22,
1446, 12073, 2,
1447, 12097, 24,
1448, 12101, 4,
1449, 12107, 6,
1450, 12109, 2,
1451, 12113, 4,
1452, 12119, 6,
1453, 12143, 24,
1454, 12149, 6,
1455, 12157, 8,
1456, 12161, 4,
1457, 12163, 2,
1458, 12197, 34,
1459, 12203, 6,
1460, 12211, 8,
1461, 12227, 16,
1462, 12239, 12,
1463, 12241, 2,
1464, 12251, 10,
1465, 12253, 2,
1466, 12263, 10,
1467, 12269, 6,
1468, 12277, 8,
1469, 12281, 4,
1470, 12289, 8,
1471, 12301, 12,
1472, 12323, 22,
1473, 12329, 6,
1474, 12343, 14,
1475, 12347, 4,
1476, 12373, 26,
1477, 12377, 4,
1478, 12379, 2,
1479, 12391, 12,
1480, 12401, 10,
1481, 12409, 8,
1482, 12413, 4,
1483, 12421, 8,
1484, 12433, 12,
1485, 12437, 4,
1486, 12451, 14,
1487, 12457, 6,
1488, 12473, 16,
1489, 12479, 6,
1490, 12487, 8,
1491, 12491, 4,
1492, 12497, 6,
1493, 12503, 6,
1494, 12511, 8,
1495, 12517, 6,
1496, 12527, 10,
1497, 12539, 12,
1498, 12541, 2,
1499, 12547, 6,
1500, 12553, 6,
1501, 12569, 16,
1502, 12577, 8,
1503, 12583, 6,
1504, 12589, 6,
1505, 12601, 12,
1506, 12611, 10,
1507, 12613, 2,
1508, 12619, 6,
1509, 12637, 18,
1510, 12641, 4,
1511, 12647, 6,
1512, 12653, 6,
1513, 12659, 6,
1514, 12671, 12,
1515, 12689, 18,
1516, 12697, 8,
1517, 12703, 6,
1518, 12713, 10,
1519, 12721, 8,
1520, 12739, 18,
1521, 12743, 4,
1522, 12757, 14,
1523, 12763, 6,
1524, 12781, 18,
1525, 12791, 10,
1526, 12799, 8,
1527, 12809, 10,
1528, 12821, 12,
1529, 12823, 2,
1530, 12829, 6,
1531, 12841, 12,
1532, 12853, 12,
1533, 12889, 36,
1534, 12893, 4,
1535, 12899, 6,
1536, 12907, 8,
1537, 12911, 4,
1538, 12917, 6,
1539, 12919, 2,
1540, 12923, 4,
1541, 12941, 18,
1542, 12953, 12,
1543, 12959, 6,
1544, 12967, 8,
1545, 12973, 6,
1546, 12979, 6,
1547, 12983, 4,
1548, 13001, 18,
1549, 13003, 2,
1550, 13007, 4,
1551, 13009, 2,
1552, 13033, 24,
1553, 13037, 4,
1554, 13043, 6,
1555, 13049, 6,
1556, 13063, 14,
1557, 13093, 30,
1558, 13099, 6,
1559, 13103, 4,
1560, 13109, 6,
1561, 13121, 12,
1562, 13127, 6,
1563, 13147, 20,
1564, 13151, 4,
1565, 13159, 8,
1566, 13163, 4,
1567, 13171, 8,
1568, 13177, 6,
1569, 13183, 6,
1570, 13187, 4,
1571, 13217, 30,
1572, 13219, 2,
1573, 13229, 10,
1574, 13241, 12,
1575, 13249, 8,
1576, 13259, 10,
1577, 13267, 8,
1578, 13291, 24,
1579, 13297, 6,
1580, 13309, 12,
1581, 13313, 4,
1582, 13327, 14,
1583, 13331, 4,
1584, 13337, 6,
1585, 13339, 2,
1586, 13367, 28,
1587, 13381, 14,
1588, 13397, 16,
1589, 13399, 2,
1590, 13411, 12,
1591, 13417, 6,
1592, 13421, 4,
1593, 13441, 20,
1594, 13451, 10,
1595, 13457, 6,
1596, 13463, 6,
1597, 13469, 6,
1598, 13477, 8,
1599, 13487, 10,
1600, 13499, 12,
1601, 13513, 14,
1602, 13523, 10,
1603, 13537, 14,
1604, 13553, 16,
1605, 13567, 14,
1606, 13577, 10,
1607, 13591, 14,
1608, 13597, 6,
1609, 13613, 16,
1610, 13619, 6,
1611, 13627, 8,
1612, 13633, 6,
1613, 13649, 16,
1614, 13669, 20,
1615, 13679, 10,
1616, 13681, 2,
1617, 13687, 6,
1618, 13691, 4,
1619, 13693, 2,
1620, 13697, 4,
1621, 13709, 12,
1622, 13711, 2,
1623, 13721, 10,
1624, 13723, 2,
1625, 13729, 6,
1626, 13751, 22,
1627, 13757, 6,
1628, 13759, 2,
1629, 13763, 4,
1630, 13781, 18,
1631, 13789, 8,
1632, 13799, 10,
1633, 13807, 8,
1634, 13829, 22,
1635, 13831, 2,
1636, 13841, 10,
1637, 13859, 18,
1638, 13873, 14,
1639, 13877, 4,
1640, 13879, 2,
1641, 13883, 4,
1642, 13901, 18,
1643, 13903, 2,
1644, 13907, 4,
1645, 13913, 6,
1646, 13921, 8,
1647, 13931, 10,
1648, 13933, 2,
1649, 13963, 30,
1650, 13967, 4,
1651, 13997, 30,
1652, 13999, 2,
1653, 14009, 10,
1654, 14011, 2,
1655, 14029, 18,
1656, 14033, 4,
1657, 14051, 18,
1658, 14057, 6,
1659, 14071, 14,
1660, 14081, 10,
1661, 14083, 2,
1662, 14087, 4,
1663, 14107, 20,
1664, 14143, 36,
1665, 14149, 6,
1666, 14153, 4,
1667, 14159, 6,
1668, 14173, 14,
1669, 14177, 4,
1670, 14197, 20,
1671, 14207, 10,
1672, 14221, 14,
1673, 14243, 22,
1674, 14249, 6,
1675, 14251, 2,
1676, 14281, 30,
1677, 14293, 12,
1678, 14303, 10,
1679, 14321, 18,
1680, 14323, 2,
1681, 14327, 4,
1682, 14341, 14,
1683, 14347, 6,
1684, 14369, 22,
1685, 14387, 18,
1686, 14389, 2,
1687, 14401, 12,
1688, 14407, 6,
1689, 14411, 4,
1690, 14419, 8,
1691, 14423, 4,
1692, 14431, 8,
1693, 14437, 6,
1694, 14447, 10,
1695, 14449, 2,
1696, 14461, 12,
1697, 14479, 18,
1698, 14489, 10,
1699, 14503, 14,
1700, 14519, 16,
1701, 14533, 14,
1702, 14537, 4,
1703, 14543, 6,
1704, 14549, 6,
1705, 14551, 2,
1706, 14557, 6,
1707, 14561, 4,
1708, 14563, 2,
1709, 14591, 28,
1710, 14593, 2,
1711, 14621, 28,
1712, 14627, 6,
1713, 14629, 2,
1714, 14633, 4,
1715, 14639, 6,
1716, 14653, 14,
1717, 14657, 4,
1718, 14669, 12,
1719, 14683, 14,
1720, 14699, 16,
1721, 14713, 14,
1722, 14717, 4,
1723, 14723, 6,
1724, 14731, 8,
1725, 14737, 6,
1726, 14741, 4,
1727, 14747, 6,
1728, 14753, 6,
1729, 14759, 6,
1730, 14767, 8,
1731, 14771, 4,
1732, 14779, 8,
1733, 14783, 4,
1734, 14797, 14,
1735, 14813, 16,
1736, 14821, 8,
1737, 14827, 6,
1738, 14831, 4,
1739, 14843, 12,
1740, 14851, 8,
1741, 14867, 16,
1742, 14869, 2,
1743, 14879, 10,
1744, 14887, 8,
1745, 14891, 4,
1746, 14897, 6,
1747, 14923, 26,
1748, 14929, 6,
1749, 14939, 10,
1750, 14947, 8,
1751, 14951, 4,
1752, 14957, 6,
1753, 14969, 12,
1754, 14983, 14,
1755, 15013, 30,
1756, 15017, 4,
1757, 15031, 14,
1758, 15053, 22,
1759, 15061, 8,
1760, 15073, 12,
1761, 15077, 4,
1762, 15083, 6,
1763, 15091, 8,
1764, 15101, 10,
1765, 15107, 6,
1766, 15121, 14,
1767, 15131, 10,
1768, 15137, 6,
1769, 15139, 2,
1770, 15149, 10,
1771, 15161, 12,
1772, 15173, 12,
1773, 15187, 14,
1774, 15193, 6,
1775, 15199, 6,
1776, 15217, 18,
1777, 15227, 10,
1778, 15233, 6,
1779, 15241, 8,
1780, 15259, 18,
1781, 15263, 4,
1782, 15269, 6,
1783, 15271, 2,
1784, 15277, 6,
1785, 15287, 10,
1786, 15289, 2,
1787, 15299, 10,
1788, 15307, 8,
1789, 15313, 6,
1790, 15319, 6,
1791, 15329, 10,
1792, 15331, 2,
1793, 15349, 18,
1794, 15359, 10,
1795, 15361, 2,
1796, 15373, 12,
1797, 15377, 4,
1798, 15383, 6,
1799, 15391, 8,
1800, 15401, 10,
1801, 15413, 12,
1802, 15427, 14,
1803, 15439, 12,
1804, 15443, 4,
1805, 15451, 8,
1806, 15461, 10,
1807, 15467, 6,
1808, 15473, 6,
1809, 15493, 20,
1810, 15497, 4,
1811, 15511, 14,
1812, 15527, 16,
1813, 15541, 14,
1814, 15551, 10,
1815, 15559, 8,
1816, 15569, 10,
1817, 15581, 12,
1818, 15583, 2,
1819, 15601, 18,
1820, 15607, 6,
1821, 15619, 12,
1822, 15629, 10,
1823, 15641, 12,
1824, 15643, 2,
1825, 15647, 4,
1826, 15649, 2,
1827, 15661, 12,
1828, 15667, 6,
1829, 15671, 4,
1830, 15679, 8,
1831, 15683, 4,
1832, 15727, 44,
1833, 15731, 4,
1834, 15733, 2,
1835, 15737, 4,
1836, 15739, 2,
1837, 15749, 10,
1838, 15761, 12,
1839, 15767, 6,
1840, 15773, 6,
1841, 15787, 14,
1842, 15791, 4,
1843, 15797, 6,
1844, 15803, 6,
1845, 15809, 6,
1846, 15817, 8,
1847, 15823, 6,
1848, 15859, 36,
1849, 15877, 18,
1850, 15881, 4,
1851, 15887, 6,
1852, 15889, 2,
1853, 15901, 12,
1854, 15907, 6,
1855, 15913, 6,
1856, 15919, 6,
1857, 15923, 4,
1858, 15937, 14,
1859, 15959, 22,
1860, 15971, 12,
1861, 15973, 2,
1862, 15991, 18,
1863, 16001, 10,
1864, 16007, 6,
1865, 16033, 26,
1866, 16057, 24,
1867, 16061, 4,
1868, 16063, 2,
1869, 16067, 4,
1870, 16069, 2,
1871, 16073, 4,
1872, 16087, 14,
1873, 16091, 4,
1874, 16097, 6,
1875, 16103, 6,
1876, 16111, 8,
1877, 16127, 16,
1878, 16139, 12,
1879, 16141, 2,
1880, 16183, 42,
1881, 16187, 4,
1882, 16189, 2,
1883, 16193, 4,
1884, 16217, 24,
1885, 16223, 6,
1886, 16229, 6,
1887, 16231, 2,
1888, 16249, 18,
1889, 16253, 4,
1890, 16267, 14,
1891, 16273, 6,
1892, 16301, 28,
1893, 16319, 18,
1894, 16333, 14,
1895, 16339, 6,
1896, 16349, 10,
1897, 16361, 12,
1898, 16363, 2,
1899, 16369, 6,
1900, 16381, 12,
1901, 16411, 30,
1902, 16417, 6,
1903, 16421, 4,
1904, 16427, 6,
1905, 16433, 6,
1906, 16447, 14,
1907, 16451, 4,
1908, 16453, 2,
1909, 16477, 24,
1910, 16481, 4,
1911, 16487, 6,
1912, 16493, 6,
1913, 16519, 26,
1914, 16529, 10,
1915, 16547, 18,
1916, 16553, 6,
1917, 16561, 8,
1918, 16567, 6,
1919, 16573, 6,
1920, 16603, 30,
1921, 16607, 4,
1922, 16619, 12,
1923, 16631, 12,
1924, 16633, 2,
1925, 16649, 16,
1926, 16651, 2,
1927, 16657, 6,
1928, 16661, 4,
1929, 16673, 12,
1930, 16691, 18,
1931, 16693, 2,
1932, 16699, 6,
1933, 16703, 4,
1934, 16729, 26,
1935, 16741, 12,
1936, 16747, 6,
1937, 16759, 12,
1938, 16763, 4,
1939, 16787, 24,
1940, 16811, 24,
1941, 16823, 12,
1942, 16829, 6,
1943, 16831, 2,
1944, 16843, 12,
1945, 16871, 28,
1946, 16879, 8,
1947, 16883, 4,
1948, 16889, 6,
1949, 16901, 12,
1950, 16903, 2,
1951, 16921, 18,
1952, 16927, 6,
1953, 16931, 4,
1954, 16937, 6,
1955, 16943, 6,
1956, 16963, 20,
1957, 16979, 16,
1958, 16981, 2,
1959, 16987, 6,
1960, 16993, 6,
1961, 17011, 18,
1962, 17021, 10,
1963, 17027, 6,
1964, 17029, 2,
1965, 17033, 4,
1966, 17041, 8,
1967, 17047, 6,
1968, 17053, 6,
1969, 17077, 24,
1970, 17093, 16,
1971, 17099, 6,
1972, 17107, 8,
1973, 17117, 10,
1974, 17123, 6,
1975, 17137, 14,
1976, 17159, 22,
1977, 17167, 8,
1978, 17183, 16,
1979, 17189, 6,
1980, 17191, 2,
1981, 17203, 12,
1982, 17207, 4,
1983, 17209, 2,
1984, 17231, 22,
1985, 17239, 8,
1986, 17257, 18,
1987, 17291, 34,
1988, 17293, 2,
1989, 17299, 6,
1990, 17317, 18,
1991, 17321, 4,
1992, 17327, 6,
1993, 17333, 6,
1994, 17341, 8,
1995, 17351, 10,
1996, 17359, 8,
1997, 17377, 18,
1998, 17383, 6,
1999, 17387, 4,
2000, 17389, 2,
2001, 17393, 4,
2002, 17401, 8,
2003, 17417, 16,
2004, 17419, 2,
2005, 17431, 12,
2006, 17443, 12,
2007, 17449, 6,
2008, 17467, 18,
2009, 17471, 4,
2010, 17477, 6,
2011, 17483, 6,
2012, 17489, 6,
2013, 17491, 2,
2014, 17497, 6,
2015, 17509, 12,
2016, 17519, 10,
2017, 17539, 20,
2018, 17551, 12,
2019, 17569, 18,
2020, 17573, 4,
2021, 17579, 6,
2022, 17581, 2,
2023, 17597, 16,
2024, 17599, 2,
2025, 17609, 10,
2026, 17623, 14,
2027, 17627, 4,
2028, 17657, 30,
2029, 17659, 2,
2030, 17669, 10,
2031, 17681, 12,
2032, 17683, 2,
2033, 17707, 24,
2034, 17713, 6,
2035, 17729, 16,
2036, 17737, 8,
2037, 17747, 10,
2038, 17749, 2,
2039, 17761, 12,
2040, 17783, 22,
2041, 17789, 6,
2042, 17791, 2,
2043, 17807, 16,
2044, 17827, 20,
2045, 17837, 10,
2046, 17839, 2,
2047, 17851, 12,
2048, 17863, 12,
2049, 17881, 18,
2050, 17891, 10,
2051, 17903, 12,
2052, 17909, 6,
2053, 17911, 2,
2054, 17921, 10,
2055, 17923, 2,
2056, 17929, 6,
2057, 17939, 10,
2058, 17957, 18,
2059, 17959, 2,
2060, 17971, 12,
2061, 17977, 6,
2062, 17981, 4,
2063, 17987, 6,
2064, 17989, 2,
2065, 18013, 24,
2066, 18041, 28,
2067, 18043, 2,
2068, 18047, 4,
2069, 18049, 2,
2070, 18059, 10,
2071, 18061, 2,
2072, 18077, 16,
2073, 18089, 12,
2074, 18097, 8,
2075, 18119, 22,
2076, 18121, 2,
2077, 18127, 6,
2078, 18131, 4,
2079, 18133, 2,
2080, 18143, 10,
2081, 18149, 6,
2082, 18169, 20,
2083, 18181, 12,
2084, 18191, 10,
2085, 18199, 8,
2086, 18211, 12,
2087, 18217, 6,
2088, 18223, 6,
2089, 18229, 6,
2090, 18233, 4,
2091, 18251, 18,
2092, 18253, 2,
2093, 18257, 4,
2094, 18269, 12,
2095, 18287, 18,
2096, 18289, 2,
2097, 18301, 12,
2098, 18307, 6,
2099, 18311, 4,
2100, 18313, 2,
2101, 18329, 16,
2102, 18341, 12,
2103, 18353, 12,
2104, 18367, 14,
2105, 18371, 4,
2106, 18379, 8,
2107, 18397, 18,
2108, 18401, 4,
2109, 18413, 12,
2110, 18427, 14,
2111, 18433, 6,
2112, 18439, 6,
2113, 18443, 4,
2114, 18451, 8,
2115, 18457, 6,
2116, 18461, 4,
2117, 18481, 20,
2118, 18493, 12,
2119, 18503, 10,
2120, 18517, 14,
2121, 18521, 4,
2122, 18523, 2,
2123, 18539, 16,
2124, 18541, 2,
2125, 18553, 12,
2126, 18583, 30,
2127, 18587, 4,
2128, 18593, 6,
2129, 18617, 24,
2130, 18637, 20,
2131, 18661, 24,
2132, 18671, 10,
2133, 18679, 8,
2134, 18691, 12,
2135, 18701, 10,
2136, 18713, 12,
2137, 18719, 6,
2138, 18731, 12,
2139, 18743, 12,
2140, 18749, 6,
2141, 18757, 8,
2142, 18773, 16,
2143, 18787, 14,
2144, 18793, 6,
2145, 18797, 4,
2146, 18803, 6,
2147, 18839, 36,
2148, 18859, 20,
2149, 18869, 10,
2150, 18899, 30,
2151, 18911, 12,
2152, 18913, 2,
2153, 18917, 4,
2154, 18919, 2,
2155, 18947, 28,
2156, 18959, 12,
2157, 18973, 14,
2158, 18979, 6,
2159, 19001, 22,
2160, 19009, 8,
2161, 19013, 4,
2162, 19031, 18,
2163, 19037, 6,
2164, 19051, 14,
2165, 19069, 18,
2166, 19073, 4,
2167, 19079, 6,
2168, 19081, 2,
2169, 19087, 6,
2170, 19121, 34,
2171, 19139, 18,
2172, 19141, 2,
2173, 19157, 16,
2174, 19163, 6,
2175, 19181, 18,
2176, 19183, 2,
2177, 19207, 24,
2178, 19211, 4,
2179, 19213, 2,
2180, 19219, 6,
2181, 19231, 12,
2182, 19237, 6,
2183, 19249, 12,
2184, 19259, 10,
2185, 19267, 8,
2186, 19273, 6,
2187, 19289, 16,
2188, 19301, 12,
2189, 19309, 8,
2190, 19319, 10,
2191, 19333, 14,
2192, 19373, 40,
2193, 19379, 6,
2194, 19381, 2,
2195, 19387, 6,
2196, 19391, 4,
2197, 19403, 12,
2198, 19417, 14,
2199, 19421, 4,
2200, 19423, 2,
2201, 19427, 4,
2202, 19429, 2,
2203, 19433, 4,
2204, 19441, 8,
2205, 19447, 6,
2206, 19457, 10,
2207, 19463, 6,
2208, 19469, 6,
2209, 19471, 2,
2210, 19477, 6,
2211, 19483, 6,
2212, 19489, 6,
2213, 19501, 12,
2214, 19507, 6,
2215, 19531, 24,
2216, 19541, 10,
2217, 19543, 2,
2218, 19553, 10,
2219, 19559, 6,
2220, 19571, 12,
2221, 19577, 6,
2222, 19583, 6,
2223, 19597, 14,
2224, 19603, 6,
2225, 19609, 6,
2226, 19661, 52,
2227, 19681, 20,
2228, 19687, 6,
2229, 19697, 10,
2230, 19699, 2,
2231, 19709, 10,
2232, 19717, 8,
2233, 19727, 10,
2234, 19739, 12,
2235, 19751, 12,
2236, 19753, 2,
2237, 19759, 6,
2238, 19763, 4,
2239, 19777, 14,
2240, 19793, 16,
2241, 19801, 8,
2242, 19813, 12,
2243, 19819, 6,
2244, 19841, 22,
2245, 19843, 2,
2246, 19853, 10,
2247, 19861, 8,
2248, 19867, 6,
2249, 19889, 22,
2250, 19891, 2,
2251, 19913, 22,
2252, 19919, 6,
2253, 19927, 8,
2254, 19937, 10,
2255, 19949, 12,
2256, 19961, 12,
2257, 19963, 2,
2258, 19973, 10,
2259, 19979, 6,
2260, 19991, 12,
2261, 19993, 2,
2262, 19997, 4,
2263, 20011, 14   };
    

    rep(i , mx ) v.pb(a[i][1]);

    ll NTC=1;
    cin>>NTC;
    ll PTC=0;
    while((PTC++)<NTC){
        // cout<<"Case #"<<PTC<<":"<<' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
