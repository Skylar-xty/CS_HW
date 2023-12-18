//
// Created by Skylar_xty on 2023/11/2.
//
#include <iostream>
#include <vector>

// 定义资源控制块（RCB）结构
struct RCB {
    int availableInstances; // 可用资源数量
    int maximumInstances;   // 最大资源数量
};

// 初始化资源控制块
RCB InitializeRCB(int maxInstances) {
    RCB rcb;
    rcb.availableInstances = maxInstances;
    rcb.maximumInstances = maxInstances;
    return rcb;
}

// 请求资源
bool RequestResource(RCB& rcb, int instancesRequested) {
    if (rcb.availableInstances >= instancesRequested) {
        rcb.availableInstances -= instancesRequested;
        return true;
    }
    return false;
}

// 释放资源
void ReleaseResource(RCB& rcb, int instancesReleased) {
    rcb.availableInstances += instancesReleased;
}

int main() {
    RCB resourceA = InitializeRCB(5); // 初始化资源A，有5个实例

    // 进程1请求资源A
    if (RequestResource(resourceA, 2)) {
        std::cout << "Process 1 acquired 2 instances of Resource A." << std::endl;
    } else {
        std::cout << "Process 1 couldn't acquire required instances of Resource A." << std::endl;
    }

    // 进程2请求资源A
    if (RequestResource(resourceA, 3)) {
        std::cout << "Process 2 acquired 3 instances of Resource A." << std::endl;
    } else {
        std::cout << "Process 2 couldn't acquire required instances of Resource A." << std::endl;
    }

    // 进程1释放资源A
    ReleaseResource(resourceA, 1);
    std::cout << "Process 1 released 1 instance of Resource A." << std::endl;

    // 进程2再次请求资源A
    if (RequestResource(resourceA, 3)) {
        std::cout << "Process 2 acquired 3 instances of Resource A." << std::endl;
    } else {
        std::cout << "Process 2 couldn't acquire required instances of Resource A." << std::endl;
    }

    return 0;
}
