#include "stdio.h"
#include "string.h"

#define CONSERVATION_MODE       "/sys/bus/platform/devices/VPC2004:00/conservation_mode"
#define FAN_MODE                "/sys/bus/platform/devices/VPC2004:00/fan_mode"
#define FN_LOCK                 "/sys/bus/platform/devices/VPC2004:00/fn_lock"

int main(int argc, char *argv[])
{
    char *argument;

    if (argc > 1)
    {
        argument = argv[1];
        if (strcmp(argument, "-h") == 0 || strcmp(argument, "--help") == 0)
        {
            printf("Usage: %s [OPTION] COMMAND\n", argv[0]);
            printf("Options:\n");
            printf("  -h, --help\t\tDisplay this help message\n");
            printf("  -v, --version\t\tDisplay the version\n");
            printf("\nCommands:\n");
            printf("  status\t\tDisplay the current status\n");
            printf("  fan\t\t\tChange the fan mode\n");
            printf("  fnlock\t\tChange the fnlock mode\n");
            printf("  conservation\t\tChange the battery conservation mode\n");
        }
        else if (strcmp(argument, "-v") == 0 || strcmp(argument, "--version") == 0)
        {
            printf("Version: 1.0.0\n");
        }
        else if (strcmp(argument, "status") == 0)
        {
            FILE *file;

            if ((file = fopen(CONSERVATION_MODE, "r")) == NULL)
            {
                printf("Error: Unable to open file\n");
                return 1;
            }
            else
            {
                char status[2];
                fread(status, 1, 1, file);
                fclose(file);

                if (status[0] == '1')
                {
                    printf("Conservation mode: ON\n");
                }
                else
                {
                    printf("Conservation mode: OFF\n");
                }
            }

            if ((file = fopen(FAN_MODE, "r")) == NULL)
            {
                printf("Error: Unable to open file\n");
                return 1;
            }
            else
            {
                char status[2];
                fread(status, 1, 1, file);
                fclose(file);

                if (status[0] == '1')
                {
                    printf("Fan mode: Standard\n");
                }
                else if (status[0] == '2')
                {
                    printf("Fan mode: Dust Cleaning\n");
                }
                else if (status[0] == '4')
                {
                    printf("Fan mode: Efficient Thermal Dissipation\n");
                }
                else
                {
                    printf("Fan mode: Super Silent\n");
                }
            }

            if ((file = fopen(FN_LOCK, "r")) == NULL)
            {
                printf("Error: Unable to open file\n");
                return 1;
            }
            else
            {
                char status[2];
                fread(status, 1, 1, file);
                fclose(file);

                if (status[0] == '1')
                {
                    printf("FN Lock: ON\n");
                }
                else
                {
                    printf("FN Lock: OFF\n");
                }
            }
        }
        else if (strcmp(argument, "conservation") == 0)
        {
            FILE *file;
            char status[2];

            if (argc > 2)
            {
                if (strcmp(argv[2], "-h") == 0 || strcmp(argv[2], "--help") == 0)
                {
                    printf("Usage: %s conservation [OPTIONS] STATUS\n", argv[0]);
                    printf("Options:\n");
                    printf("  -h, --help\tDisplay this help message\n");
                    printf("\nCommands:\n");
                    printf("  on, 1\t\tEnable conservation mode\n");
                    printf("  off, 0\tDisable conservation mode\n");
                }
                else if (strcmp(argv[2], "on") == 0 || strcmp(argv[2], "1") == 0)
                {
                    if ((file = fopen(CONSERVATION_MODE, "w")) == NULL)
                    {
                        printf("Error: Unable to open file\n");
                        return 1;
                    }
                    else
                    {
                        fwrite("1", 1, 1, file);
                        fclose(file);
                        printf("Conservation mode: ON\n");
                    }
                }
                else if (strcmp(argv[2], "off") == 0 || strcmp(argv[2], "0") == 0)
                {
                    if ((file = fopen(CONSERVATION_MODE, "w")) == NULL)
                    {
                        printf("Error: Unable to open file\n");
                        return 1;
                    }
                    else
                    {
                        fwrite("0", 1, 1, file);
                        fclose(file);
                        printf("Conservation mode: OFF\n");
                    }
                }
                else
                {
                    printf("Unknown argument: %s\n", argv[2]);
                    return 1;
                }
            }
            else
            {
                if ((file = fopen(CONSERVATION_MODE, "r")) == NULL)
                {
                    printf("Error: Unable to open file\n");
                    return 1;
                }
                else
                {
                    fread(status, 1, 1, file);
                    fclose(file);
                }

                if (status[0] == '1')
                {
                    if ((file = fopen(CONSERVATION_MODE, "w")) == NULL)
                    {
                        printf("Error: Unable to open file\n");
                        return 1;
                    }
                    else
                    {
                        fwrite("0", 1, 1, file);
                        fclose(file);
                    }
                }
                else
                {
                    if ((file = fopen(CONSERVATION_MODE, "w")) == NULL)
                    {
                        printf("Error: Unable to open file\n");
                        return 1;
                    }
                    else
                    {
                        fwrite("1", 1, 1, file);
                        fclose(file);
                    }
                }

                printf("Conservation mode: %s\n", status[0] == '1' ? "OFF" : "ON");
            }
        }
        else if (strcmp(argument, "fan") == 0)
        {
            FILE *file;
            char status[2];

            if (argc > 2)
            {
                if (strcmp(argv[2], "-h") == 0 || strcmp(argv[2], "--help") == 0)
                {
                    printf("Usage: %s fan [OPTIONS] STATUS\n", argv[0]);
                    printf("Options:\n");
                    printf("  -h, --help\tDisplay this help message\n");
                    printf("\nStatus:\n");
                    printf("  silent, 0\tSuper Silent mode\n");
                    printf("  standard, 1\tStandard mode\n");
                    printf("  dust, 2\tDust Cleaning mode\n");
                    printf("  thermal, 4\tEfficient Thermal Dissipation mode\n");
                }
                else if (strcmp(argv[2], "silent") == 0 || strcmp(argv[2], "0") == 0)
                {
                    if ((file = fopen(FAN_MODE, "w")) == NULL)
                    {
                        printf("Error: Unable to open file\n");
                        return 1;
                    }
                    else
                    {
                        fwrite("0", 1, 1, file);
                        fclose(file);
                        printf("Fan mode: Super Silent\n");
                    }
                }
                else if (strcmp(argv[2], "standard") == 0 || strcmp(argv[2], "1") == 0)
                {
                    if ((file = fopen(FAN_MODE, "w")) == NULL)
                    {
                        printf("Error: Unable to open file\n");
                        return 1;
                    }
                    else
                    {
                        fwrite("1", 1, 1, file);
                        fclose(file);
                        printf("Fan mode: Standard\n");
                    }
                }
                else if (strcmp(argv[2], "dust") == 0 || strcmp(argv[2], "2") == 0)
                {
                    if ((file = fopen(FAN_MODE, "w")) == NULL)
                    {
                        printf("Error: Unable to open file\n");
                        return 1;
                    }
                    else
                    {
                        fwrite("2", 1, 1, file);
                        fclose(file);
                        printf("Fan mode: Dust Cleaning\n");
                    }
                }
                else if (strcmp(argv[2], "thermal") == 0 || strcmp(argv[2], "4") == 0)
                {
                    if ((file = fopen(FAN_MODE, "w")) == NULL)
                    {
                        printf("Error: Unable to open file\n");
                        return 1;
                    }
                    else
                    {
                        fwrite("4", 1, 1, file);
                        fclose(file);
                        printf("Fan mode: Efficient Thermal Dissipation\n");
                    }
                }
                else
                {
                    if ((file = fopen(FAN_MODE, "r")) == NULL)
                    {
                        printf("Error: Unable to open file\n");
                        return 1;
                    }
                    else
                    {
                        fread(status, 1, 1, file);
                        fclose(file);
                    }

                    if (status[0] == '1')
                    {
                        if ((file = fopen(FAN_MODE, "w")) == NULL)
                        {
                            printf("Error: Unable to open file\n");
                            return 1;
                        }
                        else
                        {
                            fwrite("0", 1, 1, file);
                            fclose(file);
                        }
                    }
                    else
                    {
                        if ((file = fopen(FAN_MODE, "w")) == NULL)
                        {
                            printf("Error: Unable to open file\n");
                            return 1;
                        }
                        else
                        {
                            fwrite("1", 1, 1, file);
                            fclose(file);
                        }
                    }

                    printf("Fan mode: %s\n", status[0] == '1' ? "Super Silent" : "Standard");
                }
            }
        }
        else if (strcmp(argument, "fnlock") == 0)
        {
            FILE *file;
            char status[2];

            if (argc > 2)
            {
                if (strcmp(argv[2], "-h") == 0 || strcmp(argv[2], "--help") == 0)
                {
                    printf("Usage: %s fnlock [OPTIONS] STATUS\n", argv[0]);
                    printf("Options:\n");
                    printf("  -h, --help\tDisplay this help message\n");
                    printf("\nStatus:\n");
                    printf("  on, 1\t\tEnable FN Lock\n");
                    printf("  off, 0\tDisable FN Lock\n");
                }
                else if (strcmp(argv[2], "on") == 0 || strcmp(argv[2], "1") == 0)
                {
                    if ((file = fopen(FN_LOCK, "w")) == NULL)
                    {
                        printf("Error: Unable to open file\n");
                        return 1;
                    }
                    else
                    {
                        fwrite("1", 1, 1, file);
                        fclose(file);
                        printf("FN Lock: ON\n");
                    }
                }
                else if (strcmp(argv[2], "off") == 0 || strcmp(argv[2], "0") == 0)
                {
                    if ((file = fopen(FN_LOCK, "w")) == NULL)
                    {
                        printf("Error: Unable to open file\n");
                        return 1;
                    }
                    else
                    {
                        fwrite("0", 1, 1, file);
                        fclose(file);
                        printf("FN Lock: OFF\n");
                    }
                }
                else
                {
                    printf("Unknown argument: %s\n", argv[2]);
                    return 1;
                }
            }
            else
            {
                if ((file = fopen(FN_LOCK, "r")) == NULL)
                {
                    printf("Error: Unable to open file\n");
                    return 1;
                }
                else
                {
                    fread(status, 1, 1, file);
                    fclose(file);
                }

                if (status[0] == '1')
                {
                    if ((file = fopen(FN_LOCK, "w")) == NULL)
                    {
                        printf("Error: Unable to open file\n");
                        return 1;
                    }
                    else
                    {
                        fwrite("0", 1, 1, file);
                        fclose(file);
                    }
                }
                else
                {
                    if ((file = fopen(FN_LOCK, "w")) == NULL)
                    {
                        printf("Error: Unable to open file\n");
                        return 1;
                    }
                    else
                    {
                        fwrite("1", 1, 1, file);
                        fclose(file);
                    }
                }

                printf("FN Lock: %s\n", status[0] == '1' ? "OFF" : "ON");
            }
        }
        else
        {
            printf("Unknown command: %s\n", argument);
        }
    }
    else
    {
        printf("No argument provided\n");
    }

    return 0;
}