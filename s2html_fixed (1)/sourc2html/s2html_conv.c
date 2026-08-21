
#include <stdio.h>
#include "s2html_event.h"
#include "s2html_conv.h"

/* BUG FIX: writes data to file after escaping HTML special characters
 * ('<' '>' '&') so that characters like '<' in source code (e.g. printf("<LIS>"))
 * don't get treated as HTML tags and disappear from the browser output.
 */
static void fprint_escaped(FILE *fp, const char *data)
{
	int i;
	for(i = 0; data[i] != '\0'; i++)
	{
		switch(data[i])
		{
			case '<':  fprintf(fp, "&lt;");  break;
			case '>':  fprintf(fp, "&gt;");  break;
			case '&':  fprintf(fp, "&amp;"); break;
			default :  fputc(data[i], fp);   break;
		}
	}
}

/* start_or_end_conv function definitation */
void html_begin(FILE* dest_fp, int type) /* type => not used, but can be used to add differnet HTML tags */
{
	/* Add HTML begining tags into destination file */
	fprintf(dest_fp, "<!DOCTYPE html>\n");
	fprintf(dest_fp, "<html lang=\"en-US\">\n");
	fprintf(dest_fp, "<head>\n");
	fprintf(dest_fp, "<title>%s</title>\n", "sode2html");
	fprintf(dest_fp, "<meta charset=\"UTF-8\">\n");
	fprintf(dest_fp, "<link rel=\"stylesheet\" href=\"styles.css\">\n");
	fprintf(dest_fp, "</head>\n");
	fprintf(dest_fp, "<body style=\"background-color:lightgrey;\">\n");
	fprintf(dest_fp, "<pre>\n");
}
void html_end(FILE* dest_fp, int type) /* type => not used, but can be used to add differnet HTML tags */
{
	/* Add HTML closing tags into destination file */
	fprintf(dest_fp, "</pre>\n");
	fprintf(dest_fp, "</body>\n");
	fprintf(dest_fp, "</html>\n");
}


/* sourc_to_html function definitation */
void source_to_html(FILE* fp, pevent_t *event)
{
#ifdef DEBUG
	printf("%s", event->data);
#endif
	switch(event->type)
	{
		case PEVENT_PREPROCESSOR_DIRECTIVE:
			fprintf(fp,"<span class=\"preprocess_dir\">");
			fprint_escaped(fp, event->data);
			fprintf(fp,"</span>");
			break;
		case PEVENT_MULTI_LINE_COMMENT:
		case PEVENT_SINGLE_LINE_COMMENT:
			fprintf(fp,"<span class=\"comment\">");
			fprint_escaped(fp, event->data);
			fprintf(fp,"</span>");
			break;
		case PEVENT_STRING:
			fprintf(fp,"<span class=\"string\">");
			fprint_escaped(fp, event->data);
			fprintf(fp,"</span>");
			break;
		case PEVENT_HEADER_FILE:
			/* write to html */
			if(event->property == USER_HEADER_FILE)
			{
				fprintf(fp,"<span class=\"header_file\">");
				fprint_escaped(fp, event->data);
				fprintf(fp,"</span>");
				// printf("%s",event->data);
			}
			else
			{
				fprintf(fp,"<span class=\"header_file\">&lt;%s&gt;</span>",event->data);
				// printf("%s",event->data);
			}
			break;
		case PEVENT_REGULAR_EXP:
		case PEVENT_EOF :
			fprint_escaped(fp, event->data);
			break;
		case PEVENT_NUMERIC_CONSTANT:
			fprintf(fp,"<span class=\"numeric_constant\">");
			fprint_escaped(fp, event->data);
			fprintf(fp,"</span>");
			break;
		case PEVENT_RESERVE_KEYWORD:
			if(event->property == RES_KEYWORD_DATA)
			{
				fprintf(fp,"<span class=\"reserved_key1\">");
				fprint_escaped(fp, event->data);
				fprintf(fp,"</span>");
			}
			else
			{
				fprintf(fp,"<span class=\"reserved_key2\">");
				fprint_escaped(fp, event->data);
				fprintf(fp,"</span>");
			}
			break;
		case PEVENT_ASCII_CHAR:
			fprintf(fp,"<span class=\"ascii_char\">");
			fprint_escaped(fp, event->data);
			fprintf(fp,"</span>");
			break;
		default :
			printf("Unknow event\n");
			break;
	}
}


