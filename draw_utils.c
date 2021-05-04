#include "visualizer.h"
#include "error_message.h"

t_rectangle	*create_rectangle(int x_start,
				int x_end,
				int y_start,
				int y_end)
{
	t_rectangle *rectangle;

	if (!(rectangle = (t_rectangle *)ft_memalloc(sizeof(t_rectangle))))
		terminate(ERR_MEMALLOC);
	rectangle->x_start = x_start;
	rectangle->x_end = x_end;
	rectangle->y_start = y_start;
	rectangle->y_end = y_end;
	return (rectangle);
}
