const int MAXN = 1e5;

class TaskManager {
  vector<int> taskPriority, taskUser;
  priority_queue<pair<int, int>> pq;

public:
  TaskManager(vector<vector<int>>& tasks) {
    taskPriority.resize(MAXN + 1, -1);
    taskUser.resize(MAXN + 1, -1);
    for (auto& task : tasks) {
      int userId = task[0], taskId = task[1], priority = task[2];
      taskPriority[taskId] = priority;
      taskUser[taskId] = userId;
      pq.push({priority, taskId});
    }
  }

  void add(int userId, int taskId, int priority) {
    taskPriority[taskId] = priority;
    taskUser[taskId] = userId;
    pq.push({priority, taskId});
  }

  void edit(int taskId, int newPriority) {
    taskPriority[taskId] = newPriority;
    pq.push({newPriority, taskId});
  }

  void rmv(int taskId) {
    taskPriority[taskId] = -1;
    taskUser[taskId] = -1;
  }

  int execTop() {
    while (!pq.empty()) {
      auto [priority, taskId] = pq.top(); pq.pop();
      if (taskPriority[taskId] == priority) {
        int ret = taskUser[taskId];
        rmv(taskId);
        return ret;
      }
    }
    return -1;
  }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
