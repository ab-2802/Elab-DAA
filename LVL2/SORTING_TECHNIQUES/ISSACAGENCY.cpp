#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Video { int l, r, index; };
struct Channel { int a, b, c, index; };

bool compareVideos(const Video &v1, const Video &v2) { return v1.l < v2.l; }
bool compareChannels(const Channel &c1, const Channel &c2) { return c1.a < c2.a; }

void town(int &x) { x *= 2; } // Reference function

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<Video> videos(n); vector<Channel> channels(m);

    for (int i = 0; i < n; i++) cin >> videos[i].l >> videos[i].r, videos[i].index = i + 1;
    for (int i = 0; i < m; i++) cin >> channels[i].a >> channels[i].b >> channels[i].c, channels[i].index = i + 1;

    sort(videos.begin(), videos.end(), compareVideos);
    sort(channels.begin(), channels.end(), compareChannels);

    int maxEfficiency = 0, bestVideo = -1, bestChannel = -1;

    for (const auto &video : videos) {
        auto it = lower_bound(channels.begin(), channels.end(), video.l, [](const Channel &c, int val) { return c.b < val; });

        for (; it != channels.end() && it->a <= video.r; ++it) {
            int x = max(video.l, it->a), y = min(video.r, it->b);
            int efficiency = (y - x) * it->c;
            if (efficiency > maxEfficiency) maxEfficiency = efficiency, bestVideo = video.index, bestChannel = it->index;
        }
    }

    cout << maxEfficiency << "\n";
    if (maxEfficiency > 0) cout << bestVideo << " " << bestChannel << "\n";
}