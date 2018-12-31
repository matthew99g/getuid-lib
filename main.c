#include "ugidlib.h"

int
main(const int argc, const char *argv[])
{
    if (argc > 2 || argc < 2)
        usageErr("%s user-name\n", argv[0]);

    uid_t uid = userIdFromName(argv[1]);
    if (uid == -1)
        errExit("Invalid Argument\n");
    
    printf("User ID: %d\n", uid);

    gid_t gid = groupIdFromName(argv[1]);
    if (gid == -1)
        errExit("Invalid Argument\n");

    printf("Group ID: %d\n", gid);

    char *user = userNameFromId(uid);
    if (user == NULL)
        errExit("Invalid Argument\n");

    printf("Username: %s\n", user);

    spwd *sPwd = getShawdowFromName(argv[1]);
    if (sPwd == NULL)
        errnoExit("getShawdowFromName | Are you root?\n");

    printf("Password Expiration: %lu\n", sPwd->sp_expire);

    fflush(stdout);
    return EXIT_SUCCESS;
}