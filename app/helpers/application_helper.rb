module ApplicationHelper
	def full_title(title=nil)
		if (title.present?)
			"Bubbl.io | #{title}"
		else
			"Bubbl.io"
		end
	end
end
