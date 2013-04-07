module BubblesHelper
	def cleanLinks(bubble)
		bubble.links.each do |i|
			if (Time.now - i.accessed_at) > 7.day
				i.destroy()
			end
		end
	end
end
