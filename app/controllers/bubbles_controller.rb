class BubblesController < ApplicationController
  #before_filter :get_real_url
  def new
    #if params[:bubble]
    #  redirect_to bubble_path(@bubble)
    #end
    @bubble = Bubble.new(params[:bubble])
    @bubble.save
    @items = @bubble.items.order("happened_at DESC")
    @item = @items.build
    @link = @bubble.links.new
  end

  def show
    @bubbles = Bubble.all
    id = get_real_url(request.url)
    #if id==-1 #comment out for deploy
    #  @bubble = Bubble.find(params[:id])
    #else
  	  @bubble = Bubble.find(id)
    #end
    @items = @bubble.items.order("happened_at DESC")
    @item = @items.build
    @links = @bubble.links.order("happened_at DESC")
    @link = @links.build
  end

  def create
  	@bubble = Bubble.new(params[:bubble])
  	if @bubble.save
      flash[:success] = "Bubble created!"
      redirect_to bubble_path(@bubble)
    else
      render 'new'
    end
  end

  def destroy
    @bubble = Bubble.find(params[:id])
    @bubble.destroy
    redirect_to root_path
  end

  def getID
    url_hash = params[:hash]
    #@bubbles = Bubble.all
    #@bubbles.each do |bubble|
    #  bubble.links.each do |link|
    #    if link.link_hash == url_hash
    #      id = bubble.id
    #    end
    #  end
    #end
    @bubbles = Bubble.includes(:link).all
    @bubbles.each do |bubble|
      if bubble.links.link_hash == url_hash
        id = bubble.id
      end
    end
    respond_to do |format|
      format.json { render :json => id.to_json }
    end
  end
end
