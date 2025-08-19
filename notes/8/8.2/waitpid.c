#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    pid_t c_pid = fork();

    if (c_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (c_pid == 0) {
        // 子进程代码
        printf("子进程 (PID: %d) 正在运行...\n", getpid());
        sleep(2); // 模拟子进程工作
        printf("子进程工作完成，即将退出。\n");
        exit(42); // 子进程退出，状态码为 42
    } else {
        // 父进程代码
        int wstatus;
        pid_t wait_pid;

        printf("父进程 (PID: %d) 正在等待子进程 %d...\n", getpid(), c_pid);

        // 阻塞等待特定的子进程c_pid
        wait_pid = waitpid(c_pid, &wstatus, 0); // options = 0, 阻塞等待

        if (wait_pid == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }

        // 检查子进程如何终止的
        if (WIFEXITED(wstatus)) {
            // 情况1：正常退出
            printf("父进程：我的孩子 %d 正常退出了，退出码是 %d\n",
                   wait_pid, WEXITSTATUS(wstatus));
        } else if (WIFSIGNALED(wstatus)) {
            // 情况2：被信号杀死
            printf("父进程：我的孩子 %d 被信号 %d 杀死了\n",
                   wait_pid, WTERMSIG(wstatus));
        } else {
            // 其他情况（如暂停）
            printf("父进程：我的孩子 %d 状态发生了变化，但不是终止。\n", wait_pid);
        }
    }

    return 0;
}
