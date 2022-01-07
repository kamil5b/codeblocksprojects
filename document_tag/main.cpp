#include "header.h"

int main()
{
    docList global_doc;
    tagList global_tag;
    doctagList relation;

    createDocumentList(global_doc);
    createTagsList(global_tag);
    createDocumentTagsList(relation);

    menu(global_doc,global_tag,relation);

    return 0;
}
