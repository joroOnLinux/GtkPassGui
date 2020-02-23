#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>

void populate_directory_tree_store(GtkTreeStore *treestore, const char *directory, GtkTreeIter *toplevel) {
    DIR *dir;
    struct dirent *entry;

    GtkTreeIter child;

    if (!(dir = opendir(directory)))
        return;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char path[1024];
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);

            gtk_tree_store_append(treestore, &child, toplevel);
            gtk_tree_store_set(treestore, &child,
                0, entry->d_name,
                -1);

            populate_directory_tree_store(treestore, path, &child);
        }
        else {
            gtk_tree_store_append(treestore, &child, toplevel);
            gtk_tree_store_set(treestore, &child,
                0, entry->d_name,
                -1);
        }
    }
    closedir(dir);
}
