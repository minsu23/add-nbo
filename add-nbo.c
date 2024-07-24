#include <stdio.h>
#include <stdint.h>
#include <limits.h>  // For UINT_MAX

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    FILE *file1 = fopen(argv[1], "rb");
    FILE *file2 = fopen(argv[2], "rb");
    if (!file1 || !file2) {
        fprintf(stderr, "파일이 열리지 않습니다.\n");
        if (file1) fclose(file1);
        if (file2) fclose(file2);
        return 1;
    }

    uint32_t num1, num2;
    size_t read1 = fread(&num1, sizeof(uint32_t), 1, file1);
    size_t read2 = fread(&num2, sizeof(uint32_t), 1, file2);

    if (read1 != 1 || read2 != 1) {
        fprintf(stderr, "파일 읽는데 오류가 발생했거나 파일이 4바이트보다 작습니다.\n");
        fclose(file1);
        fclose(file2);
        return 1;
    }


    fclose(file1);
    fclose(file2);


    num1 = ntohl(num1);
    num2 = ntohl(num2);

    uint32_t sum = num1 + num2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, sum, sum);

    return 0;
}
